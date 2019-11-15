// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget/PopupMenuWidget.h"
#include "MainMenu.generated.h"

class UCreateGameWidget;

/**
 * 
 */
UCLASS()
class FISTWORLD_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
    //UMainMenu( const FObjectInitializer& ObjectInitializer );

    UFUNCTION( BlueprintCallable )
    bool HasGame() const;

    UFUNCTION( BlueprintCallable )
    void ExitGame();

    UFUNCTION( BlueprintCallable )
    void ShowAboutWidget();

    UFUNCTION( BlueprintCallable )
    void ShowCreateGameWidget();

    UFUNCTION( BlueprintCallable )
    void ShowOptionWidget();

    UFUNCTION( BlueprintCallable )
    void BtnContinueClicked();

    void StartExistsGame();
protected:
        
    UPopupMenuWidget* CreatePopupMenu( TSubclassOf<UPopupMenuWidget> className, FName name );
    UPopupMenuWidget *aboutWidget, *optionWidget;
    UCreateGameWidget* createGameWidget;
};
