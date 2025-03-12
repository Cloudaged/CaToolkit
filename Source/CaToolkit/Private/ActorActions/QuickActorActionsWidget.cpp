// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorActions/QuickActorActionsWidget.h"

#include "Editor.h"
#include "ToolkitDebug.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Elements/Framework/TypedElementQueryBuilder.h"
#include "Engine/Texture.h"
#include "Materials/MaterialInterface.h"

void UQuickActorActionsWidget::SelectAllActorsWithSimilarName()
{
	if(!GetEditorActorSubSystem()) return;
	TArray<AActor*> selectedActors =  editorActorSubsystem->GetSelectedLevelActors();
	uint32 selectedActorsCount = 0;
		
	if(selectedActors.Num()==0)
	{
		ShowNotifyInfo(TEXT("No actors selected"));
		return;
	}
	
	if(selectedActors.Num()>1)
	{
		ShowNotifyInfo(TEXT("Select only one actor"));
		return;
	}
	
	FString selectedActorName = selectedActors[0]->GetActorLabel();
	FString nameToSearch = selectedActorName.LeftChop(4);
	TArray<AActor*> allLevelActors = editorActorSubsystem->GetAllLevelActors();
	
	for(AActor* actor : allLevelActors)
	{
		if(!actor) continue;
		if(actor->GetActorLabel().Contains(nameToSearch,searchCase))
		{
			editorActorSubsystem->SetActorSelectionState(actor,true);
			selectedActorsCount++;
		}
	}
	
	if(selectedActorsCount>0)
	{
		ShowNotifyInfo(TEXT("Successfully selected ")
			+FString::FromInt(selectedActorsCount)
			+TEXT(" actors"));
	}
	else
	{
		ShowNotifyInfo(TEXT("No actors found with similar name"));
	}
}
#pragma region ActorRandomTransform

void UQuickActorActionsWidget::RandomizeActorTransform()
{
	const bool conditionNotSet  = !randomActorRotation.bRandomizeRotYaw;

	if(conditionNotSet)
	{
		ShowNotifyInfo(TEXT("Did not set randomization for rotation"));
	}
	if(!GetEditorActorSubSystem()) return;
	TArray<AActor*> selectedActors =  editorActorSubsystem->GetSelectedLevelActors();
	uint32 actorsCount = 0;
	
	if(selectedActors.Num()==0)
	{
		ShowNotifyInfo(TEXT("No actors selected"));
		return;
	}
	
	for(AActor* actor : selectedActors)
	{
		if(!actor) continue;

		if(randomActorRotation.bRandomizeRotYaw)
		{
			const float randomRotYawValue = FMath::RandRange(randomActorRotation.rowYawMin,randomActorRotation.rowYawMax);
			actor->AddActorWorldRotation(FRotator(0,randomRotYawValue,0));
		}

		if(randomActorRotation.bRandomizeRotYaw)
		{
			actorsCount++;
		}
	}
}
#pragma endregion 

void UQuickActorActionsWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	TArray<AActor*> selectedActors =  editorActorSubsystem->GetSelectedLevelActors();
	float totalTriangleCount = 0;
	float totalVertexCount = 0;
	float meshMemory = 0;
	float textureMemory = 0;
	for(AActor* actor : selectedActors)
	{
		//get mesh count
		UActorComponent* actorComp = actor->GetComponentByClass(UStaticMeshComponent::StaticClass());
		if(UStaticMeshComponent* meshComp = Cast<UStaticMeshComponent>(actorComp))
		{
			totalTriangleCount += meshComp->GetStaticMesh()->GetNumTriangles(meshComp->MinLOD);
			totalVertexCount += meshComp->GetStaticMesh()->GetNumVertices(meshComp->MinLOD);
			meshMemory += meshComp->GetStaticMesh()->GetResourceSizeBytes(EResourceSizeMode::EstimatedTotal);
			TSet<UTexture*> textureSet;
			//get texture memory
			for(int i=0;i<meshComp->GetNumMaterials();i++)
			{
				if(UMaterialInterface* matInterface = meshComp->GetMaterial(i))
				{
					TArray<UTexture*> textureArray;
					TArray<TArray<int>> foo;
					matInterface->GetUsedTexturesAndIndices(textureArray,foo,
						EMaterialQualityLevel::Epic,ERHIFeatureLevel::SM6);
					for(UTexture* texture : textureArray)
					{
						if(!textureSet.Contains(texture))
						{
							textureMemory += texture->GetResourceSizeBytes(EResourceSizeMode::EstimatedTotal);
							textureSet.Add(texture);
						}
					}
				}
			}
		}
	}
	float transToMB = 1024*1024;
	actorGPUProfileData.triangleCount = totalTriangleCount;
	actorGPUProfileData.vertexCount = totalVertexCount;
	actorGPUProfileData.meshMemory = meshMemory/transToMB;
	actorGPUProfileData.textureMemory = textureMemory/transToMB;
}

void UQuickActorActionsWidget::DuplicateActors()
{
	if(!GetEditorActorSubSystem()) return;
	TArray<AActor*> selectedActors = editorActorSubsystem->GetSelectedLevelActors();
	uint32 counter = 0;

	if(selectedActors.Num()==0)
	{
		ShowNotifyInfo(TEXT("No actors selected"));
	}

	if(numberOfDuplicates<=0|| offsetDist==0)
	{
		ShowNotifyInfo(TEXT("Did not specify number of duplication"));
		return;
	}

	for(AActor* actor : selectedActors)
	{
		if(!actor) continue;
		for(int i=0;i<numberOfDuplicates;i++)
		{
			AActor* duplicatedActor = editorActorSubsystem->DuplicateActor(actor,actor->GetWorld());

			if(!duplicatedActor) continue;

			float duplicationOffsetDist = (i+1) * offsetDist;

			switch (duplicationAxis)
			{
				case E_DuplicationAxis::EDA_XAxis:
					duplicatedActor->SetActorLocation(duplicatedActor->GetActorLocation()+FVector(duplicationOffsetDist,0,0));
					break;
				case E_DuplicationAxis::EDA_YAxis:
					duplicatedActor->SetActorLocation(duplicatedActor->GetActorLocation()+FVector(0,duplicationOffsetDist,0));
					break;
				case E_DuplicationAxis::EDA_ZAxis:
					duplicatedActor->SetActorLocation(duplicatedActor->GetActorLocation()+FVector(0,0,duplicationOffsetDist));
					break;
				default:
					break;
			}

			editorActorSubsystem->SetActorSelectionState(duplicatedActor,true);
			counter++;
		}

		if(counter>0)
		{
			ShowNotifyInfo(TEXT("Successfully duplicated ")
				+FString::FromInt(counter)
				+TEXT(" actors"));
		}
		else
		{
			ShowNotifyInfo(TEXT("Failed to duplicate actors"));
		}
	}
	
}

bool UQuickActorActionsWidget::GetEditorActorSubSystem()
{
	if(!editorActorSubsystem)
	{
		editorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	}
	return editorActorSubsystem!=nullptr;
}
