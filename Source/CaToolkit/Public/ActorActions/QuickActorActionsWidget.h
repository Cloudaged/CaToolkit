// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Subsystems/EditorActorSubsystem.h"
#include "QuickActorActionsWidget.generated.h"

UENUM(BlueprintType)
enum class E_DuplicationAxis:uint8
{
	EDA_XAxis UMETA (DisplayName = "X Axis"),
	EDA_YAxis UMETA (DisplayName = "Y Axis"),
	EDA_ZAxis UMETA (DisplayName = "Z Axis"),
	EDA_MAX UMETA (DisplayName = "Default Max")
};

USTRUCT(BlueprintType)
struct FRandomActorRotation
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bRandomizeRotYaw = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float rowYawMin = -45.f;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float rowYawMax = 45.f;
};

USTRUCT(BlueprintType)
struct FActorGPUProfileData
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float meshMemory = 0.f;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	 float textureMemory = 0.f;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	 float vertexCount = 0.f;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	 float triangleCount = 0.f;
};
/**
 * 
 */
UCLASS()
class CATOOLKIT_API UQuickActorActionsWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SelectAllActorsWithSimilarName();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor Batch Selection")
	TEnumAsByte<ESearchCase::Type> searchCase = ESearchCase::IgnoreCase;
#pragma region ActorRandomTransform
	UFUNCTION(BlueprintCallable)
	void RandomizeActorTransform();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor Random Transform")
	FRandomActorRotation randomActorRotation;
#pragma endregion 

#pragma region ActorGPUProfileData
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Actor GPU Profile Data")
	FActorGPUProfileData actorGPUProfileData;

	void GetActorGPUProfileData();
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
#pragma endregion
	
	
#pragma region ActorBatchDuplication
	UFUNCTION(BlueprintCallable)
	void DuplicateActors();

	 UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor Batch Duplication")
	E_DuplicationAxis duplicationAxis = E_DuplicationAxis::EDA_XAxis;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor Batch Duplication")
	int numberOfDuplicates = 5;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Actor Batch Duplication")
	float offsetDist = 300.f;
#pragma endregion 
private:
	UPROPERTY()
	UEditorActorSubsystem* editorActorSubsystem;
	
	bool GetEditorActorSubSystem();
};