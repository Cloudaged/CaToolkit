// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "Modules/ModuleManager.h"

class FCaToolkitModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
#pragma region ContentBrowserMenuExtension

	void InitCBMenuExtension();
	TArray<FString> folderPathSelected;
	TSharedRef<FExtender> CustomCBMenuExtender(const TArray<FString>& selectedPaths);
	void AddCBMenuEntry(FMenuBuilder& menuBuilder);
	void OnDeleteUnusedAssetButtonClicked();
	void OnDeleteEmptyFoldersButtonClicked();
	void FixupRedirectors();
#pragma endregion 
};
