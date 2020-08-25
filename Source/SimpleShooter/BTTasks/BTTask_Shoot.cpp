// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController.h"
#include "BTTask_Shoot.h"
#include "Kismet/GameplayStatics.h"
#include "SimpleShooter/Characters/ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);	
	
	if (OwnerComp.GetAIOwner() == nullptr)
	{	
		return EBTNodeResult::Failed; 
	}

	AShooterCharacter* AIGunner = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (AIGunner == nullptr) 
	{ 
		return EBTNodeResult::Failed; 
	}

	AIGunner->PullTrigger();

	return EBTNodeResult::Succeeded;
}