#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CXGameModeBase.generated.h"

class ACXPlayerController;

/**
 * ChatX 게임의 기본 게임 모드 클래스
 */
UCLASS()
class CHATX_API ACXGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    ACXGameModeBase();

    virtual void BeginPlay() override;
    virtual void OnPostLogin(AController* NewPlayer) override;

    FString GenerateSecretNumber();
    bool IsGuessNumberString(const FString& InNumberString);
    FString JudgeResult(const FString& InSecretNumberString, const FString& InGuessNumberString);
    void PrintChatMessageString(ACXPlayerController* InChattingPlayerController, const FString& InChatMessageString);
    void IncreaseGuessCount(ACXPlayerController* InChattingPlayerController);
    void ResetGame();
    void JudgeGame(ACXPlayerController* InChattingPlayerController, int InStrikeCount);

protected:
    FString SecretNumberString;
    TArray<TObjectPtr<ACXPlayerController>> AllPlayerControllers;
}; 