// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PopupWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UPopupWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    void Popup( int baseZOrder = 0 );
    //UPopupWidget( const FObjectInitializer& ObjectInitializer );
    //static UPopupWidget* Popup( UWorld* world );

    UFUNCTION( BlueprintCallable )
    void Quit();

    UFUNCTION( BlueprintImplementableEvent )
    void RefreshData();

protected:
    //virtual TSubclassOf<UPopupWidget> GetInstanceClass() = 0;
    //virtual bool OverrideInputMode( bool &showMouseCursor );
    virtual bool OverrideShowMouseCursor( bool& showMouseCursor );
    virtual bool OverrideInputMode( class AModeOverridableController* pc );

    struct {
        bool setted;
        bool origin;
    } m_override_mouse;
    bool m_b_override_input_mode;

private:
    APlayerController* GetPlayerController( APlayerController* &pc );
};
