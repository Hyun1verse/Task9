#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CXPlayerController.generated.h"

class UCXChatInput;
class UUserWidget;

/**
 * ChatX 게임의 플레이어 컨트롤러 클래스
 */
UCLASS()
class CHATX_API ACXPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ACXPlayerController();

    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
    virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

    void SetChatMessageString(const FString& InChatMessageString);
    void PrintChatMessageString(const FString& InChatMessageString);

    UFUNCTION(Client, Reliable)
    void ClientRPCPrintChatMessageString(const FString& InChatMessageString);

    UFUNCTION(Server, Reliable)
    void ServerRPCPrintChatMessageString(const FString& InChatMessageString);

public:
    UPROPERTY(Replicated, BlueprintReadOnly)
    FText NotificationText;

protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UCXChatInput> ChatInputWidgetClass;
    
    UPROPERTY()
    TObjectPtr<UCXChatInput> ChatInputWidgetInstance;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UUserWidget> NotificationTextWidgetClass;
    
    UPROPERTY()
    TObjectPtr<UUserWidget> NotificationTextWidgetInstance;

    FString ChatMessageString;
}; 