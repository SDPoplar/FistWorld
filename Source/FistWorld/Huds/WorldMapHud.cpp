// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapHud.h"
#include "Widget/KingdomSummaryWidget.h"
#include "Widget/SysMenuWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"

AWorldMapHud::AWorldMapHud()
{
    //  Super();
    static ConstructorHelpers::FClassFinder<USysMenuWidget> sysmenufinder( TEXT( "/Game/Levels/Res_lv_World/Widget_World_SysMenu" ) );
    sysmenuClass = sysmenufinder.Succeeded() ? sysmenufinder.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UKingdomSummaryWidget> topsummary( TEXT( "/Game/Levels/Res_lv_World/Widget_World_TopSummary" ) );
    topsummaryClass = topsummary.Succeeded() ? topsummary.Class : nullptr;
}

void AWorldMapHud::BeginPlay()
{
    this->LoadTopSummaryWidget();
}

void AWorldMapHud::LoadTopSummaryWidget()
{
    this->m_kingdom_summary_widget = topsummaryClass
        ? UKingdomSummaryWidget::Create( topsummaryClass, GetWorld(), "Top Kingdom Summary" )
        : nullptr;
    if( !this->m_kingdom_summary_widget )
    {
        UE_LOG( LogTemp, Error, TEXT( "Failed to load top summary widget" ) );
        return;
    }
    this->m_kingdom_summary_widget->BindKingdom( UFistWorldInstance::GetInstance( this )->GetMyKingdom() );
    this->m_kingdom_summary_widget->AddToViewport();
}
