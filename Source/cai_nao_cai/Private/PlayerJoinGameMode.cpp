// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerJoinGameMode.h"

void APlayerJoinGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

    // GetNumPlayers() at the PreLogin stage does not yet include the player attempting to join
    // Host counts as 1 player, so rejection starts when there are already 4 players
    if (GetNumPlayers() >= 4)
    {
        ErrorMessage = TEXT("Servidor cheio (4/4). Tente novamente mais tarde!");
    }
}