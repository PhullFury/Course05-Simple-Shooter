// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_ClearBlackboardValues.h"

UBTTask_ClearBlackboardValues::UBTTask_ClearBlackboardValues() 
{
	NodeName = TEXT("Clear Blackboard Values");
}

EBTNodeResult::Type UBTTask_ClearBlackboardValues::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult::Succeeded;
}