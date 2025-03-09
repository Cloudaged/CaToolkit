// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetAction/QuickAssetAction.h"

#include "Engine/Engine.h"
#include "EditorUtilityLibrary.h"
#include "EditorAssetLibrary.h"
#include "ToolkitDebug.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Misc/MessageDialog.h"
#include "ObjectTools.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
void UQuickAssetAction::DuplicateAssets(int duplicatesNum)
{
	if(duplicatesNum<=0)
	{
		ShowMsgDialog(EAppMsgType::Ok,TEXT("Duplicates number must be greater than 0"),true);	
		return;
	}

	TArray<FAssetData> selectedData = UEditorUtilityLibrary::GetSelectedAssetData();
	int counter = 0;
	for(const auto& assetData : selectedData)
	{
		for(int i = 0;i<duplicatesNum;i++)
		{
			const FString sourceAssetPath = assetData.ObjectPath.ToString();
			const FString newduplicatedAssetName = assetData.AssetName.ToString()+"_"+FString::FromInt(i+1);
			const FString newduplicatedAssetPath = FPaths::Combine(assetData.PackagePath.ToString(),newduplicatedAssetName);

			//Duplicate
			auto obj =UEditorAssetLibrary::DuplicateAsset(sourceAssetPath,newduplicatedAssetPath);
			if(obj)
			{
				//Make it constant
				UEditorAssetLibrary::SaveAsset(newduplicatedAssetPath,false);
				counter++;
			}
		}

		if(counter)
		{
			ShowNotifyInfo(TEXT("Successfully duplicated "+FString::FromInt(counter)+" files"));
			//Print(TEXT("Successfully duplicated "+FString::FromInt(counter)+" files"),FColor::Green);
		}
	}
}

void UQuickAssetAction::AddPrefixes()
{
	TArray<UObject*> selectedObjs = UEditorUtilityLibrary::GetSelectedAssets();
	int counter = 0;
	for(auto obj: selectedObjs)
	{
		if(!obj) continue;

		FString* prefix =  prefixMap.Find(obj->GetClass());
		if(!prefix||prefix->IsEmpty())
		{
			Print(TEXT("No prefix found for "+obj->GetClass()->GetName()),FColor::Red);
			continue;
		}
		FString oldName = obj->GetName();

		if(oldName.StartsWith(*prefix))
		{
			Print(TEXT("Already prefixed "+oldName),FColor::Yellow);
			continue;
		}
        
        if(obj->IsA<UMaterialInstanceConstant>())
        {
	        oldName.RemoveFromStart(TEXT("M_"));
        	oldName.RemoveFromEnd(TEXT("_Inst"));
        }
		
		FString nameWithPrefix = *prefix+oldName;

		UEditorUtilityLibrary::RenameAsset(obj,nameWithPrefix); 
		counter++;
	}
	
	if(counter)
	{
		ShowNotifyInfo(TEXT("Successfully added prefixes to "+FString::FromInt(counter)+" files"));
	}
}

void UQuickAssetAction::RemoveUnusedAssets()
{
	TArray<FAssetData> selectedData = UEditorUtilityLibrary::GetSelectedAssetData();
	TArray<FAssetData> unusedAssetData;

	//Fix up redirectors cased by moving assets
	FixUpRedirectors();
	
	for(const FAssetData& assetData : selectedData)
	{
		TArray<FString> assetRef = UEditorAssetLibrary::FindPackageReferencersForAsset(assetData.ObjectPath.ToString());
		if(assetRef.Num()==0)
		{
			unusedAssetData.Add(assetData);
		}
	}

	if(unusedAssetData.Num()==0)
	{
		ShowMsgDialog(EAppMsgType::Ok,TEXT("No unused assets found"),true);
		return;
	}

	//delete then
	int deletedCount = ObjectTools::DeleteAssets(unusedAssetData);
	if(deletedCount==0) return;

	ShowNotifyInfo(TEXT("Successfully deleted "+FString::FromInt(deletedCount)+" unused assets"));
}

void UQuickAssetAction::FixUpRedirectors()
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
