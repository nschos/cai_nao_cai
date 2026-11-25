// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PlayerJoinGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CAI_NAO_CAI_API APlayerJoinGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	UFUNCTION(BlueprintCallable, Category = "Game")
    void StartCaiNaoCaiAndLockJoin();

	UFUNCTION(BlueprintCallable, Category = "Game")
    void EndCaiNaoCaiAndAllowJoin();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
    bool bCaiNaoCaiStarted = false;
};
