// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ActorActions/QuickActorActionsWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CATOOLKIT_QuickActorActionsWidget_generated_h
#error "QuickActorActionsWidget.generated.h already included, missing '#pragma once' in QuickActorActionsWidget.h"
#endif
#define CATOOLKIT_QuickActorActionsWidget_generated_h

#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRandomActorRotation_Statics; \
	CATOOLKIT_API static class UScriptStruct* StaticStruct();


template<> CATOOLKIT_API UScriptStruct* StaticStruct<struct FRandomActorRotation>();

#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FActorGPUProfileData_Statics; \
	CATOOLKIT_API static class UScriptStruct* StaticStruct();


template<> CATOOLKIT_API UScriptStruct* StaticStruct<struct FActorGPUProfileData>();

#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_52_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDuplicateActors); \
	DECLARE_FUNCTION(execRandomizeActorTransform); \
	DECLARE_FUNCTION(execSelectAllActorsWithSimilarName);


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_52_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuickActorActionsWidget(); \
	friend struct Z_Construct_UClass_UQuickActorActionsWidget_Statics; \
public: \
	DECLARE_CLASS(UQuickActorActionsWidget, UEditorUtilityWidget, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CaToolkit"), NO_API) \
	DECLARE_SERIALIZER(UQuickActorActionsWidget)


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_52_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuickActorActionsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UQuickActorActionsWidget(UQuickActorActionsWidget&&); \
	UQuickActorActionsWidget(const UQuickActorActionsWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuickActorActionsWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuickActorActionsWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuickActorActionsWidget) \
	NO_API virtual ~UQuickActorActionsWidget();


#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_49_PROLOG
#define FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_52_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_52_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_52_INCLASS_NO_PURE_DECLS \
	FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h_52_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CATOOLKIT_API UClass* StaticClass<class UQuickActorActionsWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_code_lib_AGProject_unreal_GoForIt2025_Plugins_CaToolkit_Source_CaToolkit_Public_ActorActions_QuickActorActionsWidget_h


#define FOREACH_ENUM_E_DUPLICATIONAXIS(op) \
	op(E_DuplicationAxis::EDA_XAxis) \
	op(E_DuplicationAxis::EDA_YAxis) \
	op(E_DuplicationAxis::EDA_ZAxis) 

enum class E_DuplicationAxis : uint8;
template<> struct TIsUEnumClass<E_DuplicationAxis> { enum { Value = true }; };
template<> CATOOLKIT_API UEnum* StaticEnum<E_DuplicationAxis>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
