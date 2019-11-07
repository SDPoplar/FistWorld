// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CommonMapHud.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API ACommonMapHud : public AHUD
{
	GENERATED_BODY()
	
public:
    //  ACommonMapHud();

    bool CloseAllPopup();
    bool ShowSysMenu();
    void PopupWidget( class UPopupWidget* widget );
    class USysMenuWidget* GetSysMenu();
protected:
    TSubclassOf<class USysMenuWidget> sysmenuClass;

private:
    class USysMenuWidget* m_widget_sysmenu;
    TArray<class UPopupWidget*> m_widgets;
};
