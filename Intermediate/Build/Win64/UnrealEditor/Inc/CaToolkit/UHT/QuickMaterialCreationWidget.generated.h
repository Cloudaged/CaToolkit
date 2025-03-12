// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AssetAction/QuickMaterialCreationWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CATOOLKIT_QuickMaterialCreationWidget_generated_h
#error "QuickMaterialCreationWidget.generated.h already included, missing '#pragma once' in QuickMaterialCreationWidget.h"
#endif
#define CATOOLKIT_QuickMaterialCreationWidget_generated_h

#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCreateMaterialFromSelectedTextures);


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickMaterialCreationWidget(); \
	friend struct Z_Construct_UClass_UQuickMaterialCreationWidget_Statics; \
public: \
	DECLARE_CLASS(UQuickMaterialCreationWidget, UEditorUtilityWidget, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CaToolkit"), NO_API) \
	DECLARE_SERIALIZER(UQuickMaterialCreationWidget)


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickMaterialCreationWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UQuickMaterialCreationWidget(UQuickMaterialCreationWidget&&); \
	UQuickMaterialCreationWidget(const UQuickMaterialCreationWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickMaterialCreationWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickMaterialCreationWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickMaterialCreationWidget) \
	NO_API virtual ~UQuickMaterialCreationWidget();


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_25_PROLOG
#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_28_INCLASS_NO_PURE_DECLS \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CATOOLKIT_API UClass* StaticClass<class UQuickMaterialCreationWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickMaterialCreationWidget_h


#define FOREACH_ENUM_E_CHANNNELPACKINGTYPE(op) \
	op(E_ChannnelPackingType::ECPT_NoChannelPacking) \
	op(E_ChannnelPackingType::ECPT_ORM) 

enum class E_ChannnelPackingType : uint8;
template<> struct TIsUEnumClass<E_ChannnelPackingType> { enum { Value = true }; };
template<> CATOOLKIT_API UEnum* StaticEnum<E_ChannnelPackingType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
