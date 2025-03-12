// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetAction/QuickMaterialCreationWidget.h"
#include "EditorAssetLibrary.h"
#include "ToolkitDebug.h"
#include "Engine/Texture2D.h"
#include "EditorUtilityLibrary.h"
#include "AssetToolsModule.h"
#include "Factories/MaterialFactoryNew.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#pragma region QuickMaterialCreationCore

void UQuickMaterialCreationWidget::CreateMaterialFromSelectedTextures()
{
	if(bCustomMaterialName)
	{
		if(MaterialName.IsEmpty()|| MaterialName.Equals(TEXT("M_")))
		{
			ShowMsgDialog(EAppMsgType::Ok,TEXT("Please input a valid material name"));
			return;
		}
	}

	TArray<FAssetData> selectedAssetsData = UEditorUtilityLibrary::GetSelectedAssetData();
	TArray<UTexture2D*> selectedTexturesArray;
	FString selectedTextureFolderPath ;
	if(!ProcessSelectedData(selectedAssetsData,selectedTexturesArray,selectedTextureFolderPath))
	{
		MaterialName = TEXT("M_"); 
		return;
	}

	if(CheckIsNameUsed(selectedTextureFolderPath,MaterialName))
	{
		return;
	}

	UMaterial* createdMaterial = CreateMaterialAsset(MaterialName,selectedTextureFolderPath);

	if(!createdMaterial)
	{
		ShowMsgDialog(EAppMsgType::Ok,TEXT("Failed to create material"));
		return;
	}

	int pinsConnectedCounter = 0;

	for(UTexture2D* selectedTexture:selectedTexturesArray)
	{
		if(!selectedTexture) continue;

		switch (channelPackingType)
		{
			case E_ChannnelPackingType::ECPT_NoChannelPacking:
				DefaultCreateMaterialNodes(createdMaterial,selectedTexture,pinsConnectedCounter);
				break;
			case E_ChannnelPackingType::ECPT_ORM:
				ORMCreateMaterialNodes(createdMaterial,selectedTexture,pinsConnectedCounter);
				break;
			case E_ChannnelPackingType::ECPT_MAX:
				break;
			default:
				break;
		}
	}

	if(bCreatedMaterialInstance)
	{
		CreateMaterialInstanceAsset(createdMaterial,MaterialName,selectedTextureFolderPath);
	}
	MaterialName = TEXT("M_"); 

	
}

bool UQuickMaterialCreationWidget::ProcessSelectedData(const TArray<FAssetData>& selectedDataToProcess,
	TArray<UTexture2D*>& outSelectedTextureArray, FString& outSelectedTexturePackagePath)
{
	if(selectedDataToProcess.Num()==0)
	{
		ShowMsgDialog(EAppMsgType::Ok,TEXT("Please select some textures"));
		return false;
	}

	bool bMaterialNameSet = false;
	
	for(const FAssetData& selectedData:selectedDataToProcess)
	{
		UObject* selectedAsset = selectedData.GetAsset();
		if(!selectedAsset) continue;

		UTexture2D* selectedTexture = Cast<UTexture2D>(selectedAsset);
		if(!selectedTexture)
		{
			ShowMsgDialog(EAppMsgType::Ok,
				TEXT("Please select textures ")+selectedAsset->GetName()+TEXT(" is not a texture"));
			return false;
		}

		outSelectedTextureArray.Add(selectedTexture);
		if(outSelectedTexturePackagePath.IsEmpty())
		{
			outSelectedTexturePackagePath = selectedData.PackagePath.ToString();
		}
		if(!bCustomMaterialName&&!bMaterialNameSet)
		{
			MaterialName = selectedAsset->GetName();
			MaterialName.RemoveFromStart(TEXT("T_"));
			MaterialName.InsertAt(0,TEXT("M_"));

			bMaterialNameSet = true;
		}
	}
	return true;

}

bool UQuickMaterialCreationWidget::CheckIsNameUsed(const FString& folderPathToCheck, const FString& materialNameToCheck)
{
	TArray<FString> existingAssetsPaths = UEditorAssetLibrary::ListAssets(folderPathToCheck,false);
	for(const FString& existingAssetPath:existingAssetsPaths)
	{
	 	const FString existingAssetName = FPaths::GetBaseFilename(existingAssetPath);
		if(existingAssetName.Equals(materialNameToCheck))
		{
			ShowMsgDialog(EAppMsgType::Ok,materialNameToCheck + TEXT(" is already exists"));
			return true;
		}
	}
	return false;
}

UMaterial* UQuickMaterialCreationWidget::CreateMaterialAsset(const FString& materialName,
	const FString& materialOutputPath)
{
	FAssetToolsModule& module = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));
	UMaterialFactoryNew* materialFactory = NewObject<UMaterialFactoryNew>();
	UObject* createdObj = module.Get().CreateAsset(materialName,materialOutputPath,UMaterial::StaticClass(),materialFactory);
	return Cast<UMaterial>(createdObj);
}

void UQuickMaterialCreationWidget::DefaultCreateMaterialNodes(UMaterial* createdMaterial, UTexture2D* selectedTexture,
	int& pinConnectedCounter)
{
	UMaterialExpressionTextureSample* textureSampleNode = NewObject<UMaterialExpressionTextureSample>(createdMaterial);
	if(!textureSampleNode)
	{
		return;
	}

	if(!createdMaterial->HasBaseColorConnected())
	{
		if(TryConnectBaseColor(textureSampleNode,selectedTexture,createdMaterial))
		{
			pinConnectedCounter++;
			return;
		}
	}

	if(!createdMaterial->HasMetallicConnected())
	{
		if(TryConnectMetallic(textureSampleNode,selectedTexture,createdMaterial))
		{
			pinConnectedCounter++;
			return;
		}
	}

	if(!createdMaterial->HasRoughnessConnected())
	{
		if(TryConnectRoughness(textureSampleNode,selectedTexture,createdMaterial))
		{
			pinConnectedCounter++;
			return;
		}
	}

	if(!createdMaterial->HasNormalConnected())
	{
		if(TryConnectNormal(textureSampleNode,selectedTexture,createdMaterial))
		{
			pinConnectedCounter++;
			return;
		}
	}

	if(!createdMaterial->HasAmbientOcclusionConnected())
	{
		if(TryConnectAO(textureSampleNode,selectedTexture,createdMaterial))
		{
			pinConnectedCounter++;	
			return;
		}
	}

	Print(TEXT("No pin connected"),FColor::Red);
}

void UQuickMaterialCreationWidget::ORMCreateMaterialNodes(UMaterial* createdMaterial, UTexture2D* selectedTexture,
	int& pinConnectedCounter)
{
	UMaterialExpressionTextureSample* textureSampleNode = NewObject<UMaterialExpressionTextureSample>(createdMaterial);
	if(!textureSampleNode)
	{
		return;
	}

	if(!createdMaterial->HasBaseColorConnected())
	{
		if(TryConnectBaseColor(textureSampleNode,selectedTexture,createdMaterial))
		{
			pinConnectedCounter++;
			return;
		}
	}
	
	if(!createdMaterial->HasNormalConnected())
	{
		if(TryConnectNormal(textureSampleNode,selectedTexture,createdMaterial))
		{
			pinConnectedCounter++;
			return;
		}
	}

	
	if(!createdMaterial->HasRoughnessConnected())
	{
		if(TryConnectORM(textureSampleNode,selectedTexture,createdMaterial))
		{
			pinConnectedCounter++;
			return;
		}
	}

	Print(TEXT("No pin connected"),FColor::Red);
}

#pragma endregion 


#pragma region CreateMaterialNodesConnectPins

bool UQuickMaterialCreationWidget::TryConnectBaseColor(UMaterialExpressionTextureSample* textureSampleNode,
	UTexture2D* selectedTexture, UMaterial* createdMaterial)
{
	for(const FString& baseColorName : baseColorArray)
	{
		if(selectedTexture->GetName().Contains(baseColorName))
		{
			textureSampleNode->Texture = selectedTexture;
			createdMaterial->GetExpressionCollection().AddExpression(textureSampleNode);
			createdMaterial->GetExpressionInputForProperty(EMaterialProperty::MP_BaseColor)->Connect(0,textureSampleNode);
			createdMaterial->PostEditChange();
			textureSampleNode->MaterialExpressionEditorX -=600;
			return true;
		}
	}
	return false;
}

bool UQuickMaterialCreationWidget::TryConnectMetallic(UMaterialExpressionTextureSample* textureSampleNode,
	UTexture2D* selectedTexture, UMaterial* createdMaterial)
{
	for(const FString& metallicName : MetallicArray)
	{
		if(selectedTexture->GetName().Contains(metallicName))
		{
			selectedTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
			selectedTexture->SRGB = false;
			selectedTexture->PostEditChange();
			textureSampleNode->Texture = selectedTexture;
			textureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_LinearColor;
			
			createdMaterial->GetExpressionCollection().AddExpression(textureSampleNode);
			createdMaterial->GetExpressionInputForProperty(EMaterialProperty::MP_Metallic)->Connect(0,textureSampleNode);
			createdMaterial->PostEditChange();
			textureSampleNode->MaterialExpressionEditorX -=600;
			textureSampleNode->MaterialExpressionEditorY +=240;
			return true;
		}
	}
	return false;
}

bool UQuickMaterialCreationWidget::TryConnectRoughness(UMaterialExpressionTextureSample* textureSampleNode,
	UTexture2D* selectedTexture, UMaterial* createdMaterial)
{
	for(const FString& roughnessName : RoughnessArray)
	{
		if(selectedTexture->GetName().Contains(roughnessName))
		{
			selectedTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
			selectedTexture->SRGB = false;
			selectedTexture->PostEditChange();
			textureSampleNode->Texture = selectedTexture;
			textureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_LinearColor;
			
			createdMaterial->GetExpressionCollection().AddExpression(textureSampleNode);
			createdMaterial->GetExpressionInputForProperty(EMaterialProperty::MP_Roughness)->Connect(0,textureSampleNode);
			createdMaterial->PostEditChange();
			textureSampleNode->MaterialExpressionEditorX -=600;
			textureSampleNode->MaterialExpressionEditorY +=480;
			return true;
		}
	}
	return false;
}

bool UQuickMaterialCreationWidget::TryConnectNormal(UMaterialExpressionTextureSample* textureSampleNode,
	UTexture2D* selectedTexture, UMaterial* createdMaterial)
{
	 for(const FString& normalName : NormalArray)
	 {
		 if(selectedTexture->GetName().Contains(normalName))
		 {
			 selectedTexture->CompressionSettings = TextureCompressionSettings::TC_Normalmap;
			 selectedTexture->SRGB = false;
			 selectedTexture->PostEditChange();
			 textureSampleNode->Texture = selectedTexture;
			 textureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_Normal;
			 
		 	createdMaterial->GetExpressionCollection().AddExpression(textureSampleNode);
		 	createdMaterial->GetExpressionInputForProperty(EMaterialProperty::MP_Normal)->Connect(0,textureSampleNode);
		 	createdMaterial->PostEditChange();
		 	textureSampleNode->MaterialExpressionEditorX -=600;
		 	textureSampleNode->MaterialExpressionEditorY +=720;
		 	return true;
		 }
	 }
	 return false;
}

bool UQuickMaterialCreationWidget::TryConnectAO(UMaterialExpressionTextureSample* textureSampleNode,
	UTexture2D* selectedTexture, UMaterial* createdMaterial)
{
	for(const FString& aoName : AmbientOcclusionArray)
	{
		if(selectedTexture->GetName().Contains(aoName))
		{
			selectedTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
			selectedTexture->SRGB = false;
			selectedTexture->PostEditChange();
			textureSampleNode->Texture = selectedTexture;
			textureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_LinearColor;
			
			createdMaterial->GetExpressionCollection().AddExpression(textureSampleNode);
			createdMaterial->GetExpressionInputForProperty(EMaterialProperty::MP_AmbientOcclusion)->Connect(0,textureSampleNode);
			createdMaterial->PostEditChange();
			textureSampleNode->MaterialExpressionEditorX -=600;
			textureSampleNode->MaterialExpressionEditorY +=960;
			return true;
		}
	}
	return false;
	
}

bool UQuickMaterialCreationWidget::TryConnectORM(UMaterialExpressionTextureSample* textureSampleNode,
	UTexture2D* selectedTexture, UMaterial* createdMaterial)
{
	for(const FString& ormName : ORMArray)
	{
		if(selectedTexture->GetName().Contains(ormName))
		{
			selectedTexture->CompressionSettings = TextureCompressionSettings::TC_Masks;
			selectedTexture->SRGB = false;
			selectedTexture->PostEditChange();

			textureSampleNode->Texture = selectedTexture;
			textureSampleNode->SamplerType = EMaterialSamplerType::SAMPLERTYPE_Masks;
			
			createdMaterial->GetExpressionCollection().AddExpression(textureSampleNode);
			createdMaterial->GetExpressionInputForProperty(EMaterialProperty::MP_AmbientOcclusion)->Connect(1,textureSampleNode);
			createdMaterial->GetExpressionInputForProperty(EMaterialProperty::MP_Roughness)->Connect(2,textureSampleNode);
			createdMaterial->GetExpressionInputForProperty(EMaterialProperty::MP_Metallic)->Connect(3,textureSampleNode);
			textureSampleNode->MaterialExpressionEditorX -=600;
			textureSampleNode->MaterialExpressionEditorY +=480;
			return true;
		}
	}
	return false;
}

UMaterialInstanceConstant* UQuickMaterialCreationWidget::CreateMaterialInstanceAsset(UMaterial* createdMaterial,
	FString nameOfInstance, const FString& outputPath)
{
	nameOfInstance.RemoveFromStart(TEXT("M_"));
	nameOfInstance.InsertAt(0,TEXT("MI_"));

	UMaterialInstanceConstantFactoryNew* miFactoryNew =    NewObject<UMaterialInstanceConstantFactoryNew>();
	
	FAssetToolsModule& module = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));
	UObject* createdObj = module.Get().CreateAsset(nameOfInstance,outputPath,UMaterialInstanceConstant::StaticClass(),miFactoryNew);

	if(UMaterialInstanceConstant * createdMI = Cast<UMaterialInstanceConstant>(createdObj))
	{
		createdMI->SetParentEditorOnly(createdMaterial);
		createdMI->PostEditChange();
		createdMaterial->PostEditChange();
		return createdMI;
	}
	return nullptr;
}
#pragma endregion
