// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Docking/SDockTab.h"

class FCaToolkitModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
#pragma region ProcessDataForAdvanceDeletionTab
	bool DeleteSingleAssetForAssetList(const FAssetData& assetDataToDelete);
	bool DeleteMultipleAssetsForAssetList(const TArray<FAssetData>& assetsToDelete);
	void ListUnusedAssetsForAssetList(const TArray<TSharedPtr<FAssetData>>& assetsDataToFilter,
		TArray<TSharedPtr<FAssetData>>& outUnusedAssetData);
	void ListSameNameAssetsForAssetList(const TArray<TSharedPtr<FAssetData>>& assetsDataToFilter,
		TArray<TSharedPtr<FAssetData>>& outSameAssetData);
	void SyncCBToClickedAssetForAssetList(const FString& assetPathToSync);
#pragma endregion
	
private:
#pragma region ContentBrowserMenuExtension

	void InitCBMenuExtension();
	TArray<FString> folderPathSelected;
	TSharedRef<FExtender> CustomCBMenuExtender(const TArray<FString>& selectedPaths);
	void AddCBMenuEntry(FMenuBuilder& menuBuilder);
	void OnDeleteUnusedAssetButtonClicked();
	void OnDeleteEmptyFoldersButtonClicked();
	void OnAdvanceDeletionButtonClicked();
	void FixupRedirectors();
#pragma endregion

#pragma region CustomEditorTab
	void RegisterAdvanceDeletionTab();
	
	TSharedRef<SDockTab> OnSpawnAdvanceDeletionTab(const FSpawnTabArgs& args);
	TArray<TSharedPtr<FAssetData>> GetAllAssetDataUnderSelectedFolder();
#pragma endregion
};
