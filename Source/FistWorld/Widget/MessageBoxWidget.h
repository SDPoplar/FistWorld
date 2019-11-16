// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "MessageBoxWidget.generated.h"

UENUM( BlueprintType )
enum class EMessageUseIcon : uint8
{
    ALERT,
    DANGER,
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UMessageBoxWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    void SetDisplayContent( EMessageUseIcon type, FString content );

    UFUNCTION( BlueprintCallable )
    EMessageUseIcon GetType() const noexcept;

    UFUNCTION( BlueprintCallable )
    FString GetContent() const noexcept;

    UFUNCTION( BlueprintCallable )
    void CheckLifetime();
protected:
    EMessageUseIcon m_e_type;
    FString m_s_content;
};
