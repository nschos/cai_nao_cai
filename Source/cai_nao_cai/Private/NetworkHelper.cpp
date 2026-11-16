// Fill out your copyright notice in the Description page of Project Settings.

#include "NetworkHelper.h"
#include "SocketSubsystem.h"

static const TCHAR* ALPHABET = TEXT("ABCDEFGHJKLMNPQRSTUVWXYZ23456789");

FString UNetworkHelper::GetLocalIPV4()
{
    bool bCanBind = false;
    TSharedRef<FInternetAddr> LocalIp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, bCanBind);
    return LocalIp->IsValid() ? LocalIp->ToString(false) : TEXT("");
}

FString UNetworkHelper::EncodeIP_ToCode(const FString& IPAddress)
{
    TArray<FString> Parts;
    IPAddress.ParseIntoArray(Parts, TEXT("."), true);
    if (Parts.Num() != 4) return TEXT("");

    uint32 Value = 0;
    for (int i = 0; i < 4; ++i)
    {
        int32 Octet = FCString::Atoi(*Parts[i]);
        if (Octet < 0 || Octet > 255) return TEXT("");
        Value = (Value << 8) | (uint32)Octet;
    }

    FString Code;
    Code.Reserve(7);
    for (int i = 6; i >= 0; --i)
    {
        Code.AppendChar(ALPHABET[(Value >> (i * 5)) & 0x1F]);
    }
    return Code;
}

FString UNetworkHelper::DecodeCode_ToIP(const FString& Code)
{
    if (Code.Len() != 7) return TEXT("");

    uint32 Value = 0;
    for (int i = 0; i < 7; ++i)
    {
        TCHAR C = FChar::ToUpper(Code[i]);
        const TCHAR* Found = FCString::Strchr(ALPHABET, C);
        if (!Found) return TEXT("");
        int32 Index = (int32)(Found - ALPHABET);
        Value = (Value << 5) | (uint32)Index;
    }

    Value &= 0xFFFFFFFF;
    uint8 A = (Value >> 24) & 0xFF;
    uint8 B = (Value >> 16) & 0xFF;
    uint8 C = (Value >> 8) & 0xFF;
    uint8 D = Value & 0xFF;
    return FString::Printf(TEXT("%d.%d.%d.%d"), A, B, C, D);
}