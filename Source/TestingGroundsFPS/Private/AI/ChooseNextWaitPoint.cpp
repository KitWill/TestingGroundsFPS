// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/AI/ChooseNextWaitPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Public/PatrollingGurad.h"
#include "Runtime/AIModule/Classes/AIController.h "



EBTNodeResult::Type UChooseNextWaitPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	APatrollingGurad *PatrollingGurad = Cast<APatrollingGurad>(ControlledPawn);
	auto PatorlPoints = PatrollingGurad->PatrolPointCPP;

	auto Blackboard = OwnerComp.GetBlackboardComponent();
	auto Index = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);
	auto PatrolPoint = PatorlPoints[Index];
	Blackboard->SetValueAsObject(WattPointKey.SelectedKeyName, PatrolPoint);

	Index += 1;
	Blackboard->SetValueAsInt(IndexKey.SelectedKeyName, Index%PatorlPoints.Num());

	return EBTNodeResult::Succeeded;
}  