// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerJoinGameMode.h"

void APlayerJoinGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
    Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

    if (!ErrorMessage.IsEmpty()) return;

    if (bCaiNaoCaiStarted)
    {
        ErrorMessage = TEXT("O jogo está em andamento. Aguarde para jogar!");
        return;
    }

    if (GetNumPlayers() >= 4)
    {
        ErrorMessage = TEXT("Servidor cheio (4/4). Tente novamente mais tarde!");
        return;
    }
}

void APlayerJoinGameMode::StartCaiNaoCaiAndLockJoin()
{
    bCaiNaoCaiStarted = true;
}

void APlayerJoinGameMode::EndCaiNaoCaiAndAllowJoin()
{
    bCaiNaoCaiStarted = false;
}