// Copyright 2019

#include "FightConfirmBackWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameModes/TownFightMode.h"

void UFightConfirmBackWidget::ConfirmBack()
{
    auto gm = Cast<ATownFightMode>( UGameplayStatics::GetGameMode( this ) );
    gm->DefencerWin();
}
