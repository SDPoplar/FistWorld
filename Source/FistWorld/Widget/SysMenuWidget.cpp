// Fill out your copyright notice in the Description page of Project Settings.

#include "SysMenuWidget.h"
#include "FistWorldSave.h"
#include "Huds/CommonMapHud.h"
#include "Kismet/GameplayStatics.h"

void USysMenuWidget::ConfirmBack()
{
    auto pc = UGameplayStatics::GetPlayerController( this, 0 );
    auto hud = pc ? Cast<ACommonMapHud>( pc->GetHUD() ) : nullptr;
    hud&& hud->PopupConfirmBackWidget();
}
