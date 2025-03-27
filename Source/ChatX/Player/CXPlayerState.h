#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CXPlayerState.generated.h"

/**
 * ChatX 게임의 플레이어 상태 클래스
 */
UCLASS()
class CHATX_API ACXPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    ACXPlayerState();
    
    virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
    
    FString GetPlayerInfoString() const;

public:
    UPROPERTY(Replicated)
    FString PlayerNameString;

    UPROPERTY(Replicated)
    int32 CurrentGuessCount = 0;

    UPROPERTY(Replicated)
    int32 MaxGuessCount = 3;
}; 