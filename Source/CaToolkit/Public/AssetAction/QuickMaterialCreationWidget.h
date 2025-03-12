// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Engine/Texture2D.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "QuickMaterialCreationWidget.generated.h"

UENUM(BlueprintType)
enum class E_ChannnelPackingType: uint8
{
	ECPT_NoChannelPacking UMETA(DisplayName="No Channel Packing"),
	ECPT_ORM UMETA(DisplayName = "OcclusionRoughnessMetallic"),
	ECPT_MAX UMETA(DisplayName = "DefaultMAX")
};



/**
 * 
 */
UCLASS()
class CATOOLKIT_API UQuickMaterialCreationWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
#pragma region QuickMaterialCreationCore
	UFUNCTION(BlueprintCallable)
	void CreateMaterialFromSelectedTextures();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CreateMaterialFromSelectedTextures")
	bool bCustomMaterialName = true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,
		Category="CreateMaterialFromSelectedTextures",meta=(EditCondition="bCustomMaterialName"))
	FString MaterialName= TEXT("M_");

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="CreateMaterialFromSelectedTextures")
	E_ChannnelPackingType channelPackingType = E_ChannnelPackingType::ECPT_NoChannelPacking;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CreateMaterialFromSelectedTextures")
	bool bCreatedMaterialInstance = false;
	
#pragma endregion

#pragma region SupportedTextureNames

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Supported Texture Names")
	TArray<FString> baseColorArray =
	{
		TEXT("_D"),
		TEXT("_BaseColor"),
		TEXT("_Color"),
		TEXT("_Diffuse"),
		TEXT("_Albedo"),
		TEXT("_diff")
	};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Supported Texture Names")
	TArray<FString> MetallicArray =
	{
		TEXT("_M"),
	    TEXT("_Metallic"),
	    TEXT("_metal")
	};

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Supported Texture Names")
TArray<FString> RoughnessArray =
{
	TEXT("_R"),
    TEXT("_Roughness"),
    TEXT("_RoughnessMap"),
    TEXT("_rough")
};

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Supported Texture Names")
TArray<FString> NormalArray =
{
	TEXT("_N"),
	TEXT("_Normal"),
    TEXT("_NormalMap"),
    TEXT("_nor")
};

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Supported Texture Names")
TArray<FString> AmbientOcclusionArray =
{
    TEXT("_AmbientOcclusion"),
    TEXT("_AmbientOcclusionMap"),
    TEXT("_AO")
};

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Supported Texture Names")
TArray<FString> ORMArray =
{
	TEXT("_ORM")
};
	
#pragma endregion 
	
#pragma region QuickMaterialCreation
	bool ProcessSelectedData(const TArray<FAssetData>& selectedDataToProcess,
		TArray<UTexture2D*>& outSelectedTextureArray,FString& outSelectedTexturePackagePath);
	bool CheckIsNameUsed(const FString& folderPathToCheck,const FString& materialNameToCheck);
	UMaterial* CreateMaterialAsset(const FString& materialName,const FString& materialOutputPath);
	void DefaultCreateMaterialNodes(UMaterial* createdMaterial,UTexture2D* selectedTexture,int& pinConnectedCounter);
	void ORMCreateMaterialNodes(UMaterial* createdMaterial,UTexture2D* selectedTexture,int& pinConnectedCounter);

#pragma endregion


#pragma region CreateMaterialNodesConnectPins
	bool TryConnectBaseColor(UMaterialExpressionTextureSample* textureSampleNode,UTexture2D* selectedTexture,UMaterial* createdMaterial);
	bool TryConnectMetallic(UMaterialExpressionTextureSample* textureSampleNode,UTexture2D* selectedTexture,UMaterial* createdMaterial);
	bool TryConnectRoughness(UMaterialExpressionTextureSample* textureSampleNode,UTexture2D* selectedTexture,UMaterial* createdMaterial);
	bool TryConnectNormal(UMaterialExpressionTextureSample* textureSampleNode,UTexture2D* selectedTexture,UMaterial* createdMaterial);
	bool TryConnectAO(UMaterialExpressionTextureSample* textureSampleNode,UTexture2D* selectedTexture,UMaterial* createdMaterial);
	bool TryConnectORM(UMaterialExpressionTextureSample* textureSampleNode,UTexture2D* selectedTexture,UMaterial* createdMaterial);
#pragma endregion

	class UMaterialInstanceConstant* CreateMaterialInstanceAsset(UMaterial* createdMaterial,FString nameOfInstance,const FString& outputPath);
};
