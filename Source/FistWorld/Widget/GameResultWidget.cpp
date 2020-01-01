// Copyright 2019

#include "GameResultWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Static/Lang/WorldMessage.h"

UGameResultWidget::UGameResultWidget( const FObjectInitializer& ObjectInitializer )
    : UPopupWidget( ObjectInitializer ), m_b_player_win( true )
{}

void UGameResultWidget::SetResult( bool playerWin )
{
    this->m_b_player_win = playerWin;
}

bool UGameResultWidget::IsPlayerWin() const noexcept
{
    return this->m_b_player_win;
}

FText UGameResultWidget::GetResultContent() const noexcept
{
    return this->m_b_player_win ? txtResultWin : txtResultLose;
}

void UGameResultWidget::PlayerConfirmed()
{
    UGameplayStatics::OpenLevel( this, "LV_MainMenu" );
}

bool UGameResultWidget::OverridePauseGame( bool& pause )
{
    pause = true;
    return true;
}
