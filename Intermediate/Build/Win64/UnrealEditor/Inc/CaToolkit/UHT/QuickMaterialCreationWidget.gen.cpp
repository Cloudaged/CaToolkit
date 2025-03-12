// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CaToolkit/Public/AssetAction/QuickMaterialCreationWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuickMaterialCreationWidget() {}

// Begin Cross Module References
BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget();
CATOOLKIT_API UClass* Z_Construct_UClass_UQuickMaterialCreationWidget();
CATOOLKIT_API UClass* Z_Construct_UClass_UQuickMaterialCreationWidget_NoRegister();
CATOOLKIT_API UEnum* Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType();
UPackage* Z_Construct_UPackage__Script_CaToolkit();
// End Cross Module References

// Begin Enum E_ChannnelPackingType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_ChannnelPackingType;
static UEnum* E_ChannnelPackingType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_E_ChannnelPackingType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_E_ChannnelPackingType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType, (UObject*)Z_Construct_UPackage__Script_CaToolkit(), TEXT("E_ChannnelPackingType"));
	}
	return Z_Registration_Info_UEnum_E_ChannnelPackingType.OuterSingleton;
}
template<> CATOOLKIT_API UEnum* StaticEnum<E_ChannnelPackingType>()
{
	return E_ChannnelPackingType_StaticEnum();
}
struct Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ECPT_MAX.DisplayName", "DefaultMAX" },
		{ "ECPT_MAX.Name", "E_ChannnelPackingType::ECPT_MAX" },
		{ "ECPT_NoChannelPacking.DisplayName", "No Channel Packing" },
		{ "ECPT_NoChannelPacking.Name", "E_ChannnelPackingType::ECPT_NoChannelPacking" },
		{ "ECPT_ORM.DisplayName", "OcclusionRoughnessMetallic" },
		{ "ECPT_ORM.Name", "E_ChannnelPackingType::ECPT_ORM" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "E_ChannnelPackingType::ECPT_NoChannelPacking", (int64)E_ChannnelPackingType::ECPT_NoChannelPacking },
		{ "E_ChannnelPackingType::ECPT_ORM", (int64)E_ChannnelPackingType::ECPT_ORM },
		{ "E_ChannnelPackingType::ECPT_MAX", (int64)E_ChannnelPackingType::ECPT_MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CaToolkit,
	nullptr,
	"E_ChannnelPackingType",
	"E_ChannnelPackingType",
	Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType()
{
	if (!Z_Registration_Info_UEnum_E_ChannnelPackingType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_ChannnelPackingType.InnerSingleton, Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_E_ChannnelPackingType.InnerSingleton;
}
// End Enum E_ChannnelPackingType

// Begin Class UQuickMaterialCreationWidget Function CreateMaterialFromSelectedTextures
struct Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickMaterialCreationWidget, nullptr, "CreateMaterialFromSelectedTextures", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickMaterialCreationWidget::execCreateMaterialFromSelectedTextures)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateMaterialFromSelectedTextures();
	P_NATIVE_END;
}
// End Class UQuickMaterialCreationWidget Function CreateMaterialFromSelectedTextures

// Begin Class UQuickMaterialCreationWidget
void UQuickMaterialCreationWidget::StaticRegisterNativesUQuickMaterialCreationWidget()
{
	UClass* Class = UQuickMaterialCreationWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CreateMaterialFromSelectedTextures", &UQuickMaterialCreationWidget::execCreateMaterialFromSelectedTextures },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuickMaterialCreationWidget);
UClass* Z_Construct_UClass_UQuickMaterialCreationWidget_NoRegister()
{
	return UQuickMaterialCreationWidget::StaticClass();
}
struct Z_Construct_UClass_UQuickMaterialCreationWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AssetAction/QuickMaterialCreationWidget.h" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCustomMaterialName_MetaData[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialName_MetaData[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "EditCondition", "bCustomMaterialName" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_channelPackingType_MetaData[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCreatedMaterialInstance_MetaData[] = {
		{ "Category", "CreateMaterialFromSelectedTextures" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_baseColorArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MetallicArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoughnessArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmbientOcclusionArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ORMArray_MetaData[] = {
		{ "Category", "Supported Texture Names" },
		{ "ModuleRelativePath", "Public/AssetAction/QuickMaterialCreationWidget.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bCustomMaterialName_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCustomMaterialName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_channelPackingType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_channelPackingType;
	static void NewProp_bCreatedMaterialInstance_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreatedMaterialInstance;
	static const UECodeGen_Private::FStrPropertyParams NewProp_baseColorArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_baseColorArray;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MetallicArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MetallicArray;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RoughnessArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RoughnessArray;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NormalArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NormalArray;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AmbientOcclusionArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AmbientOcclusionArray;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ORMArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ORMArray;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickMaterialCreationWidget_CreateMaterialFromSelectedTextures, "CreateMaterialFromSelectedTextures" }, // 332198833
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickMaterialCreationWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName_SetBit(void* Obj)
{
	((UQuickMaterialCreationWidget*)Obj)->bCustomMaterialName = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName = { "bCustomMaterialName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuickMaterialCreationWidget), &Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCustomMaterialName_MetaData), NewProp_bCustomMaterialName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MaterialName = { "MaterialName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, MaterialName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialName_MetaData), NewProp_MaterialName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_channelPackingType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_channelPackingType = { "channelPackingType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, channelPackingType), Z_Construct_UEnum_CaToolkit_E_ChannnelPackingType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_channelPackingType_MetaData), NewProp_channelPackingType_MetaData) }; // 72766271
void Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreatedMaterialInstance_SetBit(void* Obj)
{
	((UQuickMaterialCreationWidget*)Obj)->bCreatedMaterialInstance = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreatedMaterialInstance = { "bCreatedMaterialInstance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuickMaterialCreationWidget), &Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreatedMaterialInstance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCreatedMaterialInstance_MetaData), NewProp_bCreatedMaterialInstance_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_baseColorArray_Inner = { "baseColorArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_baseColorArray = { "baseColorArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, baseColorArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_baseColorArray_MetaData), NewProp_baseColorArray_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray_Inner = { "MetallicArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray = { "MetallicArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, MetallicArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MetallicArray_MetaData), NewProp_MetallicArray_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray_Inner = { "RoughnessArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray = { "RoughnessArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, RoughnessArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoughnessArray_MetaData), NewProp_RoughnessArray_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray_Inner = { "NormalArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray = { "NormalArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, NormalArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalArray_MetaData), NewProp_NormalArray_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray_Inner = { "AmbientOcclusionArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray = { "AmbientOcclusionArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, AmbientOcclusionArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmbientOcclusionArray_MetaData), NewProp_AmbientOcclusionArray_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray_Inner = { "ORMArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray = { "ORMArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickMaterialCreationWidget, ORMArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ORMArray_MetaData), NewProp_ORMArray_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCustomMaterialName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MaterialName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_channelPackingType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_channelPackingType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_bCreatedMaterialInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_baseColorArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_baseColorArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_MetallicArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_RoughnessArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_NormalArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_AmbientOcclusionArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::NewProp_ORMArray,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorUtilityWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CaToolkit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::ClassParams = {
	&UQuickMaterialCreationWidget::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UQuickMaterialCreationWidget()
{
	if (!Z_Registration_Info_UClass_UQuickMaterialCreationWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickMaterialCreationWidget.OuterSingleton, Z_Construct_UClass_UQuickMaterialCreationWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuickMaterialCreationWidget.OuterSingleton;
}
template<> CATOOLKIT_API UClass* StaticClass<UQuickMaterialCreationWidget>()
{
	return UQuickMaterialCreationWidget::StaticClass();
}
UQuickMaterialCreationWidget::UQuickMaterialCreationWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UQuickMaterialCreationWidget);
UQuickMaterialCreationWidget::~UQuickMaterialCreationWidget() {}
// End Class UQuickMaterialCreationWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ E_ChannnelPackingType_StaticEnum, TEXT("E_ChannnelPackingType"), &Z_Registration_Info_UEnum_E_ChannnelPackingType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 72766271U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuickMaterialCreationWidget, UQuickMaterialCreationWidget::StaticClass, TEXT("UQuickMaterialCreationWidget"), &Z_Registration_Info_UClass_UQuickMaterialCreationWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickMaterialCreationWidget), 2219984335U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_3037514368(TEXT("/Script/CaToolkit"),
	Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
