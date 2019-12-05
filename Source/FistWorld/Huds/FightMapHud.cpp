// Copyright 2019

#include "FightMapHud.h"
#include "UObject/ConstructorHelpers.h"
#include "Widget/FightResultWidget.h"

AFightMapHud::AFightMapHud( const FObjectInitializer& ObjectInitializer )
    : ACommonMapHud( ObjectInitializer ), m_widget_result( nullptr )
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
