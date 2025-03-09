// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetActionUtility.h"
#include "Engine/Blueprint.h"

#include "Engine/StaticMesh.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/Texture2D.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstance.h"
#include "Animation/AnimSequence.h"
#include "Sound/SoundWave.h"
#include "Particles/ParticleSystem.h"
#include "Engine/Level.h"
#include "Blueprint/UserWidget.h"
#include "Materials/MaterialInstanceConstant.h"


#include "QuickAssetAction.generated.h"

/**
 * 
 */
UCLASS()
class CATOOLKIT_API UQuickAssetAction : public UAssetActionUtility
{
	GENERATED_BODY()
public:
	UFUNCTION(CallInEditor)
	void DuplicateAssets(int duplicatesNum);

	UFUNCTION(CallInEditor)
	void AddPrefixes();

	UFUNCTION(CallInEditor)
	void RemoveUnusedAssets();
	
private:
	TMap<UClass*,FString> prefixMap
	{
		{ UBlueprint::StaticClass(), "BP_" },
		{ UStaticMesh::StaticClass(), "SM_" },
		{ USkeletalMesh::StaticClass(), "SK_" },
		{ UTexture2D::StaticClass(), "T_" },
		{ UMaterial::StaticClass(), "M_" },
		{ UMaterialInstanceConstant::StaticClass(), "MI_" },
		{ UAnimSequence::StaticClass(), "ASeq_" },
		{ USoundWave::StaticClass(), "S_" },
		{ UParticleSystem::StaticClass(), "PS_" },
		{ ULevel::StaticClass(), "LV_" }
	};

	void FixUpRedirectors();
};
