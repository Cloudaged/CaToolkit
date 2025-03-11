// Copyright Epic Games, Inc. All Rights Reserved.

#include "CaToolkit.h"

#include "ContentBrowserModule.h"
#include "Shader.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ToolkitDebug.h"
#include "EditorAssetLibrary.h"
#include "ObjectTools.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "SlateWidgets/AdvanceDeletionWidget.h"

#define LOCTEXT_NAMESPACE "FCaToolkitModule"

void FCaToolkitModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	InitCBMenuExtension();
	RegisterAdvanceDeletionTab();
}

void FCaToolkitModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}
#pragma region ContentBrowserMenuExtension
void FCaToolkitModule::InitCBMenuExtension()
{
	FContentBrowserModule& contentModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	//Get contentBrowserMenuExtender ref, otherwise doesn't work.
	TArray<FContentBrowserMenuExtender_SelectedPaths>& contentBrowserMenuExtender = contentModule.GetAllPathViewContextMenuExtenders();

	
	FContentBrowserMenuExtender_SelectedPaths customCBMenuDelegate;
	// customCBMenuDelegate.BindRaw(this, &FCaToolkitModule::CustomCBMenuExtender);//First binding to define the position for inserting menu entry
	// contentBrowserMenuExtender.Add(customCBMenuDelegate);

	contentBrowserMenuExtender.Add(FContentBrowserMenuExtender_SelectedPaths::CreateRaw(this, &FCaToolkitModule::CustomCBMenuExtender));
}

TSharedRef<FExtender> FCaToolkitModule::CustomCBMenuExtender(const TArray<FString>& selectedPaths)
{
	TSharedRef<FExtender> menuExtender(new FExtender());

	if(selectedPaths.Num()>0)
	{
		menuExtender->AddMenuExtension(
			FName("Delete"),
			EExtensionHook::After,
			TSharedPtr<FUICommandList>(),//hotkey
			FMenuExtensionDelegate::CreateRaw(this, &FCaToolkitModule::AddCBMenuEntry)//Second binding,define detail for menu entry(Title,tooltips,function)
		);

		folderPathSelected = selectedPaths;
	}
	 return menuExtender;
}

void FCaToolkitModule::AddCBMenuEntry(FMenuBuilder& menuBuilder)
{
	menuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Delete unused entry")),
		FText::FromString(TEXT("Safely delete unused assets under this folder")),
		FSlateIcon(),
		FExecuteAction::CreateRaw(this, &FCaToolkitModule::OnDeleteUnusedAssetButtonClicked)//Third bind,The actually execute func
	);

	menuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Delete empty folders")),
		FText::FromString(TEXT("Remove empty folders under this folder")),
		FSlateIcon(),
		FExecuteAction::CreateRaw(this, &FCaToolkitModule::OnDeleteEmptyFoldersButtonClicked)
	);

	menuBuilder.AddMenuEntry
	(
		FText::FromString(TEXT("Advance deletion")),
		FText::FromString(TEXT("List assets by specific condition")),
		FSlateIcon(),
		FExecuteAction::CreateRaw(this, &FCaToolkitModule::OnAdvanceDeletionButtonClicked)
	);
}

void FCaToolkitModule::OnDeleteUnusedAssetButtonClicked()
{
	Print(TEXT("OnDeleteUnusedAssetButtonClicked"), FColor::Red);

	if(folderPathSelected.Num()>1)
	{
		ShowMsgDialog(EAppMsgType::Ok, TEXT("Please select only one folder"));
		return;	
	}
	
	TArray<FString> assetPathNames = UEditorAssetLibrary::ListAssets(folderPathSelected[0],true,false);
	if(assetPathNames.IsEmpty())
	{
		ShowMsgDialog(EAppMsgType::Ok, TEXT("No assets found in this folder"));
		return;
	}
	if(ShowMsgDialog(EAppMsgType::YesNo, TEXT("Are you sure to delete all unused assets in this folder?")) == EAppReturnType::Yes)
	{
		FixupRedirectors();
		
		TArray<FAssetData> unusedAssetsData;

		for(const FString& assetPathName : assetPathNames)
		{
			if(assetPathName.Contains(TEXT("Developers"))|| assetPathName.Contains(TEXT("Collections")))
			{
				continue;
			}

			if(!UEditorAssetLibrary::DoesAssetExist(assetPathName)) continue;

			TArray<FString> assetReference = UEditorAssetLibrary::FindPackageReferencersForAsset(assetPathName);

			if(assetReference.IsEmpty())
			{
				FAssetData assetData = UEditorAssetLibrary::FindAssetData(assetPathName);
				unusedAssetsData.Add(assetData);
			}
		}

		if(unusedAssetsData.Num()>0)
		{
			ObjectTools::DeleteAssets(unusedAssetsData);
		}
		else
		{
			ShowMsgDialog(EAppMsgType::Ok, TEXT("No unused assets found in this folder"));
		}
	}
}
void FCaToolkitModule::OnDeleteEmptyFoldersButtonClicked()
{
	FixupRedirectors();
	TArray<FString> folderPathArray =  UEditorAssetLibrary::ListAssets(folderPathSelected[0],true,true);
	uint32 counter = 0;
	FString emptyFolderPathName;
	TArray<FString> emptyFolderPathArray;

	for(const FString &folderPath : folderPathArray)
	{
		if(folderPath.Contains(TEXT("Developers"))|| folderPath.Contains(TEXT("Collections"))||
			folderPath.Contains(TEXT("__ExternalActors__"))|| folderPath.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}
		if(!UEditorAssetLibrary::DoesDirectoryExist(folderPath)) continue;

		if(!UEditorAssetLibrary::DoesDirectoryHaveAssets(folderPath))
		{
			emptyFolderPathName.Append(folderPath);
			emptyFolderPathName.Append(TEXT("\n"));
			emptyFolderPathArray.Add(folderPath);
		}
	}

	if(emptyFolderPathArray.Num()==0)
	{
		ShowMsgDialog(EAppMsgType::Ok, TEXT("No empty folders found in this folder"));
		return;
	}
	EAppReturnType::Type result = ShowMsgDialog(EAppMsgType::OkCancel, TEXT("Empty folders found in:\n"+emptyFolderPathName+"\nAre you sure to delete all empty folders?"));

	if(result == EAppReturnType::Cancel)
	{
		return;
	}

	for(const FString& emptyFolderPath : emptyFolderPathArray)
	{
		if(UEditorAssetLibrary::DeleteDirectory(emptyFolderPath))
		{
			++counter;
		}else
		{
			Print(TEXT("Failed to delete folder:")+emptyFolderPath, FColor::Red);
		}
	}
	if(counter>0)
	{
		ShowNotifyInfo(TEXT("Deleted "+FString::FromInt(counter)+" empty folders"));
	}
	
}

void FCaToolkitModule::OnAdvanceDeletionButtonClicked()
{
	FixupRedirectors();
	FGlobalTabmanager::Get()->TryInvokeTab(FName("AdvanceDeletion"));	
}

void FCaToolkitModule::FixupRedirectors()
{
	//reditectors need to fixed
	TArray<UObjectRedirector*> redirectorsToFixArray;

	//load asset registry module which allowed to query res in proj
	FAssetRegistryModule& assetRegistryModule = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));

	//Set the objectRedirector filter, to find all objectRedirector obj in /Games
	FARFilter filter;
	filter.bRecursivePaths = true;//Allow into subPath
	filter.PackagePaths.Add(FName("/Game"));
	filter.ClassNames.Add("ObjectRedirector");

	//Get the outRedirectors
	TArray<FAssetData> outRedirectors;
	assetRegistryModule.Get().GetAssets(filter, outRedirectors);

	//then add all redirectors to fix array
	for(const FAssetData& assetData : outRedirectors)
	{
		UObject* asset = assetData.GetAsset();
		if(asset && asset->IsA<UObjectRedirector>())
		{
			UObjectRedirector* redirector = Cast<UObjectRedirector>(assetData.GetAsset());
			redirectorsToFixArray.Add(redirector);
		}
	}
	
	//The module will help us to fix the redirectors
	FAssetToolsModule& assetToolsModule =FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));
	//send asset need to fix to assetToolsModule.
	assetToolsModule.Get().FixupReferencers(redirectorsToFixArray);
}
#pragma endregion


#pragma region CustomEditorTab
void FCaToolkitModule::RegisterAdvanceDeletionTab()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(FName("AdvanceDeletion"),
		FOnSpawnTab::CreateRaw(this, &FCaToolkitModule::OnSpawnAdvanceDeletionTab))
	.SetDisplayName(FText::FromString("Advance Deletion"));
}

TSharedRef<SDockTab> FCaToolkitModule::OnSpawnAdvanceDeletionTab(const FSpawnTabArgs& args)
{
	
	return	SNew(SDockTab).TabRole(ETabRole::NomadTab)
	[
		SNew(SAdvanceDeletionTab)
		.AssetsDataArray(FCaToolkitModule::GetAllAssetDataUnderSelectedFolder())
		.CurrentSelectedFolder(folderPathSelected[0])
	];
}

TArray<TSharedPtr<FAssetData>> FCaToolkitModule::GetAllAssetDataUnderSelectedFolder()
{
	TArray<TSharedPtr<FAssetData>> availableAssetData;
	TArray<FString> assetPathNames = UEditorAssetLibrary::ListAssets(folderPathSelected[0],true,false);
	for(const FString &assetPathName : assetPathNames)
	{
		if(assetPathName.Contains(TEXT("Developers"))|| assetPathName.Contains(TEXT("Collections"))||
			assetPathName.Contains(TEXT("__ExternalActors__"))|| assetPathName.Contains(TEXT("__ExternalObjects__")))
		{
			continue;
		}
		if(!UEditorAssetLibrary::DoesAssetExist(assetPathName)) continue;
		const FAssetData data =  UEditorAssetLibrary::FindAssetData(assetPathName);
		availableAssetData.Add(MakeShared<FAssetData>(data)) ;
	}
	return availableAssetData;
}

#pragma endregion

#pragma region ProcessDataForAdvanceDeletionTab
bool FCaToolkitModule::DeleteSingleAssetForAssetList(const FAssetData& assetDataToDelete)
{
	TArray<FAssetData> assetDataForDeletion;
	assetDataForDeletion.Add(assetDataToDelete);
	if(ObjectTools::DeleteAssets(assetDataForDeletion)>0)
	{
		return true;
	}
	return false;
}

bool FCaToolkitModule::DeleteMultipleAssetsForAssetList(const TArray<FAssetData>& assetsToDelete)
{
	if(ObjectTools::DeleteAssets(assetsToDelete)>0)
	{
		return true;
	}
	return false;
}

void FCaToolkitModule::ListUnusedAssetsForAssetList(const TArray<TSharedPtr<FAssetData>>& assetsDataToFilter,
	TArray<TSharedPtr<FAssetData>>& outUnusedAssetData)
{
	outUnusedAssetData.Empty();
	for(const TSharedPtr<FAssetData>& assetData : assetsDataToFilter)
	{
		TArray<FString> assetReferencers = UEditorAssetLibrary::FindPackageReferencersForAsset(assetData->ObjectPath.ToString());
		
		if(assetReferencers.Num()==0)
		{
			outUnusedAssetData.Add(assetData);
		}
	}
}

void FCaToolkitModule::ListSameNameAssetsForAssetList(const TArray<TSharedPtr<FAssetData>>& assetsDataToFilter,
	TArray<TSharedPtr<FAssetData>>& outSameAssetData)
{
	outSameAssetData.Empty();
	TMultiMap<FString,TSharedPtr<FAssetData>> assetInfoMap;
	for(const TSharedPtr<FAssetData>& assetData : assetsDataToFilter)
	{
		assetInfoMap.Add(assetData->AssetName.ToString(),assetData);
	}

	for(const TSharedPtr<FAssetData>& assetData : assetsDataToFilter)
	{
		TArray<TSharedPtr<FAssetData>> outAssetData ;
		assetInfoMap.MultiFind(assetData->AssetName.ToString(),outAssetData);//Find all data that have the same name
		if(outAssetData.Num()<=1)continue;

		for(const TSharedPtr<FAssetData>& sameAssetData : outAssetData)
		{
			if(sameAssetData.IsValid())
			{
				outSameAssetData.AddUnique(sameAssetData);
			}
		}
	}
}

void FCaToolkitModule::SyncCBToClickedAssetForAssetList(const FString& assetPathToSync)
{
	TArray<FString> assetPaths;
	assetPaths.Add(assetPathToSync);
	UEditorAssetLibrary::SyncBrowserToObjects(assetPaths);
}
#pragma endregion 
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCaToolkitModule, CaToolkit)