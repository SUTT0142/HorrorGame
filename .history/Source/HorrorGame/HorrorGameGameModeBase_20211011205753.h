// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HorrorGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class HORRORGAME_API AHorrorGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void StartPlay() override; // Allows you to override StartPlay to print a log message to screen when gameplay begins
};
