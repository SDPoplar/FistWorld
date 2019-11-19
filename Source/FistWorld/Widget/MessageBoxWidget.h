// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include <ctime>
#include "MessageBoxWidget.generated.h"

UENUM( BlueprintType )
enum class EMessageUseIcon : uint8
{
    ALERT,
    DANGER,
    SUCCESS,
    FAILED
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

    UPROPERTY( EditDefaultsOnly )
    int lifeTime;
protected:
    EMessageUseIcon m_e_type;
    FText m_s_content;
    time_t m_display_time;
};
