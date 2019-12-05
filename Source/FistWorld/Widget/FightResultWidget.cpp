// Copyright 2019

#include "FightResultWidget.h"
#include "Static/Lang/FightInfo.h"
#include "GameModes/TownFightMode.h"

const FSlateColor WinnerColor = FSlateColor( FLinearColor( 0.025, 0.604, 0.019 ) );
const FSlateColor LoserColor = FSlateColor( FLinearColor( 0.250, 0.007, 0 ) );

void FillResult( UTextBlock* shower, TArray<FText> allInfo, bool useWinnerColor )
{
    if( !shower )
    {
        return;
    }
    FString content = "";
    for( auto item : allInfo )
    {
        if( !content.IsEmpty() )
        {
            content += "\n";
        }
        content += item.ToString();
    }
    shower->SetText( FText::FromString( content ) );
    shower->SetColorAndOpacity( useWinnerColor ? WinnerColor : LoserColor );
}

void UFightResultWidget::SetFightResult( bool playerIsAttacker, bool attackerWin,
    TArray<FText> attackerResult, TArray<FText> defencerResult )
{
    this->m_b_attacker_win = attackerWin;
    UTextBlock* shower = this->GetResultTitle();
    if( shower )
    {
        if( playerIsAttacker == attackerWin )
        {
            shower->SetText( txtFightResultWin );
            shower->SetColorAndOpacity( WinnerColor );
        }
        else
        {
            shower->SetText( txtFightResultLost );
            shower->SetColorAndOpacity( LoserColor );
        }
    }
    FillResult( this->GetAttackerResultShower(), attackerResult, attackerWin );
    FillResult( this->GetDefencerResultShower(), defencerResult, !attackerWin );
}

void UFightResultWidget::ResultConfirmed()
{
    auto mode = ATownFightMode::Get( this );
    if( mode )
    {
        if( this->m_b_attacker_win )
        {
            mode->AttackerWin();
        }
        else
        {
            mode->DefencerWin();
        }
    }
    this->Quit();
}
