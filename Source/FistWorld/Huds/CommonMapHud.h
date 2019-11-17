// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widget/MessageBoxWidget.h"
#include "CommonMapHud.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API ACommonMapHud : public AHUD
{
	GENERATED_BODY()
	
public:
    ACommonMapHud( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    bool CloseAllPopup();
    bool ShowSysMenu();
    bool PopupAlert( FString content );
    //  bool PopupDanger();

    bool PopupMessage( EMessageUseIcon type, FString content );
    void PopupWidget( class UPopupWidget* widget, int zOrder = 0 );
    class USysMenuWidget* GetSysMenu();

protected:
    class UMessageBoxWidget* GetMessageBox();

    TSubclassOf<class USysMenuWidget> sysmenuClass;
private:
    TSubclassOf<UMessageBoxWidget> msgboxClass;
    class USysMenuWidget* m_widget_sysmenu;
    UMessageBoxWidget* m_widget_message;
    TArray<class UPopupWidget*> m_widgets;
};
