#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CXGameStateBase.generated.h"

/**
 * ChatX 게임의 게임 스테이트 클래스
 */
UCLASS()
class CHATX_API ACXGameStateBase : public AGameStateBase
{
    GENERATED_BODY()

public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastRPCBroadcastLoginMessage(const FString& InNameString = FString(TEXT("XXXXXXX")));
}; 