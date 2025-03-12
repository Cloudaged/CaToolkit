// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CaToolkit/Public/ActorActions/QuickActorActionsWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuickActorActionsWidget() {}

// Begin Cross Module References
BLUTILITY_API UClass* Z_Construct_UClass_UEditorUtilityWidget();
CATOOLKIT_API UClass* Z_Construct_UClass_UQuickActorActionsWidget();
CATOOLKIT_API UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister();
CATOOLKIT_API UEnum* Z_Construct_UEnum_CaToolkit_E_DuplicationAxis();
CATOOLKIT_API UScriptStruct* Z_Construct_UScriptStruct_FActorGPUProfileData();
CATOOLKIT_API UScriptStruct* Z_Construct_UScriptStruct_FRandomActorRotation();
COREUOBJECT_API UEnum* Z_Construct_UEnum_CoreUObject_ESearchCase();
UNREALED_API UClass* Z_Construct_UClass_UEditorActorSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_CaToolkit();
// End Cross Module References

// Begin Enum E_DuplicationAxis
static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_DuplicationAxis;
static UEnum* E_DuplicationAxis_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton)
	{
		Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CaToolkit_E_DuplicationAxis, (UObject*)Z_Construct_UPackage__Script_CaToolkit(), TEXT("E_DuplicationAxis"));
	}
	return Z_Registration_Info_UEnum_E_DuplicationAxis.OuterSingleton;
}
template<> CATOOLKIT_API UEnum* StaticEnum<E_DuplicationAxis>()
{
	return E_DuplicationAxis_StaticEnum();
}
struct Z_Construct_UEnum_CaToolkit_E_DuplicationAxis_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EDA_MAX.DisplayName", "Default Max" },
		{ "EDA_MAX.Name", "E_DuplicationAxis::EDA_MAX" },
		{ "EDA_XAxis.DisplayName", "X Axis" },
		{ "EDA_XAxis.Name", "E_DuplicationAxis::EDA_XAxis" },
		{ "EDA_YAxis.DisplayName", "Y Axis" },
		{ "EDA_YAxis.Name", "E_DuplicationAxis::EDA_YAxis" },
		{ "EDA_ZAxis.DisplayName", "Z Axis" },
		{ "EDA_ZAxis.Name", "E_DuplicationAxis::EDA_ZAxis" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "E_DuplicationAxis::EDA_XAxis", (int64)E_DuplicationAxis::EDA_XAxis },
		{ "E_DuplicationAxis::EDA_YAxis", (int64)E_DuplicationAxis::EDA_YAxis },
		{ "E_DuplicationAxis::EDA_ZAxis", (int64)E_DuplicationAxis::EDA_ZAxis },
		{ "E_DuplicationAxis::EDA_MAX", (int64)E_DuplicationAxis::EDA_MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CaToolkit_E_DuplicationAxis_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_CaToolkit,
	nullptr,
	"E_DuplicationAxis",
	"E_DuplicationAxis",
	Z_Construct_UEnum_CaToolkit_E_DuplicationAxis_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_CaToolkit_E_DuplicationAxis_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_CaToolkit_E_DuplicationAxis_Statics::Enum_MetaDataParams), Z_Construct_UEnum_CaToolkit_E_DuplicationAxis_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_CaToolkit_E_DuplicationAxis()
{
	if (!Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton, Z_Construct_UEnum_CaToolkit_E_DuplicationAxis_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_E_DuplicationAxis.InnerSingleton;
}
// End Enum E_DuplicationAxis

// Begin ScriptStruct FRandomActorRotation
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RandomActorRotation;
class UScriptStruct* FRandomActorRotation::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRandomActorRotation, (UObject*)Z_Construct_UPackage__Script_CaToolkit(), TEXT("RandomActorRotation"));
	}
	return Z_Registration_Info_UScriptStruct_RandomActorRotation.OuterSingleton;
}
template<> CATOOLKIT_API UScriptStruct* StaticStruct<FRandomActorRotation>()
{
	return FRandomActorRotation::StaticStruct();
}
struct Z_Construct_UScriptStruct_FRandomActorRotation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRandomizeRotYaw_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rowYawMin_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rowYawMax_MetaData[] = {
		{ "Category", "RandomActorRotation" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bRandomizeRotYaw_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRandomizeRotYaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_rowYawMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_rowYawMax;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRandomActorRotation>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_SetBit(void* Obj)
{
	((FRandomActorRotation*)Obj)->bRandomizeRotYaw = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw = { "bRandomizeRotYaw", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FRandomActorRotation), &Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRandomizeRotYaw_MetaData), NewProp_bRandomizeRotYaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_rowYawMin = { "rowYawMin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, rowYawMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rowYawMin_MetaData), NewProp_rowYawMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_rowYawMax = { "rowYawMax", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRandomActorRotation, rowYawMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rowYawMax_MetaData), NewProp_rowYawMax_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_bRandomizeRotYaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_rowYawMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewProp_rowYawMax,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRandomActorRotation_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CaToolkit,
	nullptr,
	&NewStructOps,
	"RandomActorRotation",
	Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::PropPointers),
	sizeof(FRandomActorRotation),
	alignof(FRandomActorRotation),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRandomActorRotation_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRandomActorRotation()
{
	if (!Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton, Z_Construct_UScriptStruct_FRandomActorRotation_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_RandomActorRotation.InnerSingleton;
}
// End ScriptStruct FRandomActorRotation

// Begin ScriptStruct FActorGPUProfileData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ActorGPUProfileData;
class UScriptStruct* FActorGPUProfileData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ActorGPUProfileData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ActorGPUProfileData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FActorGPUProfileData, (UObject*)Z_Construct_UPackage__Script_CaToolkit(), TEXT("ActorGPUProfileData"));
	}
	return Z_Registration_Info_UScriptStruct_ActorGPUProfileData.OuterSingleton;
}
template<> CATOOLKIT_API UScriptStruct* StaticStruct<FActorGPUProfileData>()
{
	return FActorGPUProfileData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FActorGPUProfileData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_meshMemory_MetaData[] = {
		{ "Category", "ActorGPUProfileData" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_textureMemory_MetaData[] = {
		{ "Category", "ActorGPUProfileData" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_vertexCount_MetaData[] = {
		{ "Category", "ActorGPUProfileData" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_triangleCount_MetaData[] = {
		{ "Category", "ActorGPUProfileData" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_meshMemory;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_textureMemory;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_vertexCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_triangleCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FActorGPUProfileData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewProp_meshMemory = { "meshMemory", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActorGPUProfileData, meshMemory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_meshMemory_MetaData), NewProp_meshMemory_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewProp_textureMemory = { "textureMemory", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActorGPUProfileData, textureMemory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_textureMemory_MetaData), NewProp_textureMemory_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewProp_vertexCount = { "vertexCount", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActorGPUProfileData, vertexCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_vertexCount_MetaData), NewProp_vertexCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewProp_triangleCount = { "triangleCount", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FActorGPUProfileData, triangleCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_triangleCount_MetaData), NewProp_triangleCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewProp_meshMemory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewProp_textureMemory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewProp_vertexCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewProp_triangleCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_CaToolkit,
	nullptr,
	&NewStructOps,
	"ActorGPUProfileData",
	Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::PropPointers),
	sizeof(FActorGPUProfileData),
	alignof(FActorGPUProfileData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FActorGPUProfileData()
{
	if (!Z_Registration_Info_UScriptStruct_ActorGPUProfileData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ActorGPUProfileData.InnerSingleton, Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_ActorGPUProfileData.InnerSingleton;
}
// End ScriptStruct FActorGPUProfileData

// Begin Class UQuickActorActionsWidget Function DuplicateActors
struct Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "DuplicateActors", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execDuplicateActors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DuplicateActors();
	P_NATIVE_END;
}
// End Class UQuickActorActionsWidget Function DuplicateActors

// Begin Class UQuickActorActionsWidget Function RandomizeActorTransform
struct Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "RandomizeActorTransform", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execRandomizeActorTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RandomizeActorTransform();
	P_NATIVE_END;
}
// End Class UQuickActorActionsWidget Function RandomizeActorTransform

// Begin Class UQuickActorActionsWidget Function SelectAllActorsWithSimilarName
struct Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuickActorActionsWidget, nullptr, "SelectAllActorsWithSimilarName", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuickActorActionsWidget::execSelectAllActorsWithSimilarName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SelectAllActorsWithSimilarName();
	P_NATIVE_END;
}
// End Class UQuickActorActionsWidget Function SelectAllActorsWithSimilarName

// Begin Class UQuickActorActionsWidget
void UQuickActorActionsWidget::StaticRegisterNativesUQuickActorActionsWidget()
{
	UClass* Class = UQuickActorActionsWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DuplicateActors", &UQuickActorActionsWidget::execDuplicateActors },
		{ "RandomizeActorTransform", &UQuickActorActionsWidget::execRandomizeActorTransform },
		{ "SelectAllActorsWithSimilarName", &UQuickActorActionsWidget::execSelectAllActorsWithSimilarName },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuickActorActionsWidget);
UClass* Z_Construct_UClass_UQuickActorActionsWidget_NoRegister()
{
	return UQuickActorActionsWidget::StaticClass();
}
struct Z_Construct_UClass_UQuickActorActionsWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ActorActions/QuickActorActionsWidget.h" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_searchCase_MetaData[] = {
		{ "Category", "Actor Batch Selection" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_randomActorRotation_MetaData[] = {
		{ "Category", "Actor Random Transform" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_actorGPUProfileData_MetaData[] = {
		{ "Category", "Actor GPU Profile Data" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_duplicationAxis_MetaData[] = {
		{ "Category", "Actor Batch Duplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_numberOfDuplicates_MetaData[] = {
		{ "Category", "Actor Batch Duplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_offsetDist_MetaData[] = {
		{ "Category", "Actor Batch Duplication" },
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_editorActorSubsystem_MetaData[] = {
		{ "ModuleRelativePath", "Public/ActorActions/QuickActorActionsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_searchCase;
	static const UECodeGen_Private::FStructPropertyParams NewProp_randomActorRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_actorGPUProfileData;
	static const UECodeGen_Private::FBytePropertyParams NewProp_duplicationAxis_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_duplicationAxis;
	static const UECodeGen_Private::FIntPropertyParams NewProp_numberOfDuplicates;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_offsetDist;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_editorActorSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_DuplicateActors, "DuplicateActors" }, // 3423434306
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_RandomizeActorTransform, "RandomizeActorTransform" }, // 4258076965
		{ &Z_Construct_UFunction_UQuickActorActionsWidget_SelectAllActorsWithSimilarName, "SelectAllActorsWithSimilarName" }, // 2671756119
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuickActorActionsWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_searchCase = { "searchCase", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, searchCase), Z_Construct_UEnum_CoreUObject_ESearchCase, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_searchCase_MetaData), NewProp_searchCase_MetaData) }; // 1208795360
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_randomActorRotation = { "randomActorRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, randomActorRotation), Z_Construct_UScriptStruct_FRandomActorRotation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_randomActorRotation_MetaData), NewProp_randomActorRotation_MetaData) }; // 899099994
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_actorGPUProfileData = { "actorGPUProfileData", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, actorGPUProfileData), Z_Construct_UScriptStruct_FActorGPUProfileData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_actorGPUProfileData_MetaData), NewProp_actorGPUProfileData_MetaData) }; // 1366222024
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_duplicationAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_duplicationAxis = { "duplicationAxis", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, duplicationAxis), Z_Construct_UEnum_CaToolkit_E_DuplicationAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_duplicationAxis_MetaData), NewProp_duplicationAxis_MetaData) }; // 640492443
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_numberOfDuplicates = { "numberOfDuplicates", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, numberOfDuplicates), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_numberOfDuplicates_MetaData), NewProp_numberOfDuplicates_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_offsetDist = { "offsetDist", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, offsetDist), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_offsetDist_MetaData), NewProp_offsetDist_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_editorActorSubsystem = { "editorActorSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuickActorActionsWidget, editorActorSubsystem), Z_Construct_UClass_UEditorActorSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_editorActorSubsystem_MetaData), NewProp_editorActorSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_searchCase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_randomActorRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_actorGPUProfileData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_duplicationAxis_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_duplicationAxis,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_numberOfDuplicates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_offsetDist,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuickActorActionsWidget_Statics::NewProp_editorActorSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UQuickActorActionsWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorUtilityWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_CaToolkit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuickActorActionsWidget_Statics::ClassParams = {
	&UQuickActorActionsWidget::StaticClass,
	"Editor",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuickActorActionsWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UQuickActorActionsWidget()
{
	if (!Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton, Z_Construct_UClass_UQuickActorActionsWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuickActorActionsWidget.OuterSingleton;
}
template<> CATOOLKIT_API UClass* StaticClass<UQuickActorActionsWidget>()
{
	return UQuickActorActionsWidget::StaticClass();
}
UQuickActorActionsWidget::UQuickActorActionsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UQuickActorActionsWidget);
UQuickActorActionsWidget::~UQuickActorActionsWidget() {}
// End Class UQuickActorActionsWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ E_DuplicationAxis_StaticEnum, TEXT("E_DuplicationAxis"), &Z_Registration_Info_UEnum_E_DuplicationAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 640492443U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRandomActorRotation::StaticStruct, Z_Construct_UScriptStruct_FRandomActorRotation_Statics::NewStructOps, TEXT("RandomActorRotation"), &Z_Registration_Info_UScriptStruct_RandomActorRotation, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRandomActorRotation), 899099994U) },
		{ FActorGPUProfileData::StaticStruct, Z_Construct_UScriptStruct_FActorGPUProfileData_Statics::NewStructOps, TEXT("ActorGPUProfileData"), &Z_Registration_Info_UScriptStruct_ActorGPUProfileData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FActorGPUProfileData), 1366222024U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuickActorActionsWidget, UQuickActorActionsWidget::StaticClass, TEXT("UQuickActorActionsWidget"), &Z_Registration_Info_UClass_UQuickActorActionsWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuickActorActionsWidget), 2337777402U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_2164712157(TEXT("/Script/CaToolkit"),
	Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
