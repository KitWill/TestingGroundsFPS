// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/AI/ChooseNextWaitPoint.h"
#include "BehaviorTree/BlackboardComponent.h"




EBTNodeResult::Type UChooseNextWaitPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto Blackboard = OwnerComp.GetBlackboardComponent();

	auto Index = Blackboard->GetValueAsInt(IndexKey.SelectedKeyName);

	return EBTNodeResult::Succeeded;
}  