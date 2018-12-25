// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/AI/ChooseNextWaitPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Public/PatrolRoute.h"
#include "Runtime/AIModule/Classes/AIController.h "



EBTNodeResult::Type UChooseNextWaitPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if (!ensure(PatrolRoute)) return EBTNodeResult::Failed;

	auto PatorlPoints = PatrolRoute->GetPatrolPointCPP();

	if (PatorlPoints.Num() == 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing Patrol Piont"));
		return EBTNodeResult::Failed;
	}

	auto Blackboard = OwnerComp.GetBlackboardComponent();
	auto Index = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);
	auto PatrolPoint = PatorlPoints[Index];
	Blackboard->SetValueAsObject(WattPointKey.SelectedKeyName, PatrolPoint);

	Index += 1;
	Blackboard->SetValueAsInt(IndexKey.SelectedKeyName, Index%PatorlPoints.Num());

	return EBTNodeResult::Succeeded;
}  