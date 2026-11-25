// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PlayerJoinGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CAI_NAO_CAI_API APlayerJoinGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;	
};
