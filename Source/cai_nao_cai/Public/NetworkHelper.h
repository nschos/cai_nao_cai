// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NetworkHelper.generated.h"

UCLASS()
class CAI_NAO_CAI_API UNetworkHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "Network")
    static FString GetLocalIPV4();
	
    UFUNCTION(BlueprintCallable, Category = "Network")
    static FString EncodeIP_ToCode(const FString& IPAddress);

    UFUNCTION(BlueprintCallable, Category = "Network")
    static FString DecodeCode_ToIP(const FString& Code);
};
