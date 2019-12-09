// Copyright 2019

#include "FightMapHud.h"
#include "UObject/ConstructorHelpers.h"
#include "Widget/FightResultWidget.h"
#include "Widget/PlayerChooseDefenceWarriorWidget.h"

AFightMapHud::AFightMapHud( const FObjectInitializer& ObjectInitializer )
    : ACommonMapHud( ObjectInitializer ), m_widget_result( nullptr ), m_widget_player_defencer_chooser( nullptr )
{
    static ConstructorHelpers::FClassFinder<USysMenuWidget> sysmenuwidget(
        TEXT( "/Game/Levels/Res_lv_Fight/Widget_Fight_SysMenu" ) );
    sysmenuClass = sysmenuwidget.Succeeded() ? sysmenuwidget.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UConfirmBackWidget> confirmback(
        TEXT( "/Game/Levels/Res_lv_Fight/Widget_Fight_ConfirmBack" ) );
    confirmbackClass = confirmback.Succeeded() ? confirmback.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UFightResultWidget> fightresult(
        TEXT( "/Game/Levels/Res_lv_Fight/Widget_Fight_FightResult" ) );
    fightresultClass = fightresult.Succeeded() ? fightresult.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UPlayerChooseDefenceWarriorWidget> pdchooser(
        TEXT( "/Game/Levels/Res_lv_Fight/Widget_Fight_PlayerChooseDefencer" ) );
    defencerClass = pdchooser.Succeeded() ? pdchooser.Class : nullptr;
}

UFightResultWidget* AFightMapHud::GetFightResultWidget()
{
    if( (!this->m_widget_result || !this->m_widget_result->IsValidLowLevelFast()) && this->fightresultClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_result = Cast<UFightResultWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->fightresultClass, "fight result" ) );
        this->m_widget_result->AddToViewport( 10 );
    }
    return this->m_widget_result;
}

UPlayerChooseDefenceWarriorWidget* AFightMapHud::GetPlayerDefencerChooser()
{
    if( (!this->m_widget_player_defencer_chooser || !this->m_widget_player_defencer_chooser->IsValidLowLevelFast() )
        && this->defencerClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_player_defencer_chooser = Cast<UPlayerChooseDefenceWarriorWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->defencerClass, "defencer chooser" ) );
        this->m_widget_player_defencer_chooser->AddToViewport( 20 );
    }
    return this->m_widget_player_defencer_chooser;
}

bool AFightMapHud::PopPlayerDefencerChooser( int townId )
{
    return !!this->GetPlayerDefencerChooser();
}
