// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AssetAction/QuickAssetAction.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CATOOLKIT_QuickAssetAction_generated_h
#error "QuickAssetAction.generated.h already included, missing '#pragma once' in QuickAssetAction.h"
#endif
#define CATOOLKIT_QuickAssetAction_generated_h

#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRemoveUnusedAssets); \
	DECLARE_FUNCTION(execAddPrefixes); \
	DECLARE_FUNCTION(execDuplicateAssets);


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickAssetAction(); \
	friend struct Z_Construct_UClass_UQuickAssetAction_Statics; \
public: \
	DECLARE_CLASS(UQuickAssetAction, UAssetActionUtility, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CaToolkit"), NO_API) \
	DECLARE_SERIALIZER(UQuickAssetAction)


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h_30_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickAssetAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UQuickAssetAction(UQuickAssetAction&&); \
	UQuickAssetAction(const UQuickAssetAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickAssetAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickAssetAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickAssetAction) \
	NO_API virtual ~UQuickAssetAction();


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h_27_PROLOG
#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h_30_INCLASS_NO_PURE_DECLS \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CATOOLKIT_API UClass* StaticClass<class UQuickAssetAction>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_AssetAction_QuickAssetAction_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
