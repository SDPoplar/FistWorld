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
    void Popup();
    //UPopupWidget( const FObjectInitializer& ObjectInitializer );
    //static UPopupWidget* Popup( UWorld* world );

    UFUNCTION( BlueprintCallable )
    void Quit();

protected:
    //virtual TSubclassOf<UPopupWidget> GetInstanceClass() = 0;
    //virtual bool OverrideInputMode( bool &showMouseCursor );
    virtual bool OverrideShowMouseCursor( bool& showMouseCursor );

    struct {
        bool setted;
        bool origin;
    } m_override_mouse;
    struct {
        bool setted;
        FInputModeDataBase* origin;
    } m_override_input_mode;

private:
    APlayerController* GetPlayerController( APlayerController* &pc );
};
