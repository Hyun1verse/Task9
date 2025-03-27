#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/SlateEnums.h"
#include "CXChatInput.generated.h"

class UEditableTextBox;

/**
 * 채팅 입력을 위한 위젯 클래스
 */
UCLASS()
class CHATX_API UCXChatInput : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UEditableTextBox> EditableTextBox_ChatInput;

    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

protected:
    UFUNCTION()
    void OnChatInputTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

    virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
}; 