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
    bool PopupAlert( FText content );
    bool PopupSuccess( FText content );
    bool PopupFailed( FText content );
    //  bool PopupDanger();
    bool PopupConfirmBackWidget();

    bool PopupMessage( EMessageUseIcon type, FText content );
    void PopupWidget( class UPopupWidget* widget );
    class USysMenuWidget* GetSysMenu();

protected:
    class UMessageBoxWidget* GetMessageBox();
    class UConfirmBackWidget* GetConfirmBackWidget();

    TSubclassOf<class USysMenuWidget> sysmenuClass;
    TSubclassOf<class UConfirmBackWidget> confirmbackClass;
private:
    TSubclassOf<UMessageBoxWidget> msgboxClass;
    class USysMenuWidget* m_widget_sysmenu;
    UMessageBoxWidget* m_widget_message;
    class UConfirmBackWidget* m_widget_confirm_back;
    TArray<class UPopupWidget*> m_widgets;
};
