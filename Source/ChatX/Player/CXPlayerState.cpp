#include "Player/CXPlayerState.h"
#include "Net/UnrealNetwork.h"

ACXPlayerState::ACXPlayerState()
    : PlayerNameString(TEXT("None"))
    , CurrentGuessCount(0)
    , MaxGuessCount(3)
{
    bReplicates = true;
}

void ACXPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ThisClass, PlayerNameString);
    DOREPLIFETIME(ThisClass, CurrentGuessCount);
    DOREPLIFETIME(ThisClass, MaxGuessCount);
}

FString ACXPlayerState::GetPlayerInfoString() const
{
    return FString::Printf(TEXT("%s(%d/%d)"), *PlayerNameString, CurrentGuessCount, MaxGuessCount);
} 