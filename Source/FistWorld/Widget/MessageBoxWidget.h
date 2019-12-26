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
    SUCCESS,
    FAILED
};

USTRUCT()
struct FMessageContent
{
    GENERATED_USTRUCT_BODY()

public:
    FMessageContent( EMessageUseIcon _type = EMessageUseIcon::ALERT, FText _content = FText::GetEmpty() )
        : type( _type ), content( _content ) {}

    EMessageUseIcon type;
    FText content;
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UMessageBoxWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    UMessageBoxWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    void SetDisplayContent( EMessageUseIcon type, FText content );

    UFUNCTION( BlueprintCallable )
    EMessageUseIcon GetType() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetContent() const noexcept;

    UFUNCTION( BlueprintCallable )
    void CheckLifetime();

protected:
    TArray<FMessageContent> messages;
    float m_f_display_time;
};
