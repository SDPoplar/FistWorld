// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapHud.h"
#include "Widget/KingdomSummaryWidget.h"
#include "Widget/SysMenuWidget.h"
#include "Widget/ShowTownWidget.h"
#include "Widget/SingleWarriorSelectWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"
#include "FistWorldInstance.h"
#include "Level/TownActor.h"
#include "Story/Town.h"

AWorldMapHud::AWorldMapHud() : ACommonMapHud()
{
    //  Super();
    static ConstructorHelpers::FClassFinder<UKingdomSummaryWidget> topsummary( TEXT( "/Game/Levels/Res_lv_World/Widget_World_StaticShower" ) );
    topsummaryClass = topsummary.Succeeded() ? topsummary.Class : nullptr;
    check( topsummaryClass && "Failed to load topsummaryClass" );
    static ConstructorHelpers::FClassFinder<UShowTownWidget> playertownwidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_PlayerTown" ) );
    playertownClass = playertownwidget.Succeeded() ? playertownwidget.Class : nullptr;
    check( playertownClass && "Failed to load playertownClass" );
    static ConstructorHelpers::FClassFinder<UShowTownWidget> hostiletownwidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_HostileTown" ) );
    hostiletownClass = hostiletownwidget.Succeeded() ? hostiletownwidget.Class : nullptr;
    check( hostiletownClass && "Failed to load hostiletownClass" );
    static ConstructorHelpers::FClassFinder<USingleWarriorSelectWidget> singlewarriorwidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_SingleWarriorSelector" ) );
    singlewarriorClass = singlewarriorwidget.Succeeded() ? singlewarriorwidget.Class : nullptr;
    check( singlewarriorClass && "Failed to load singlewarriorClass" );
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

void AWorldMapHud::ShowTownInfo( UTown* town )
{
    if( !town )
    {
        return;
    }
    if( town->OwnByPlayer( this ) )
    {
        this->PopupPlayerTownWidget( town );
    }
    else
    {
        this->PopupHostileTownWidget( town );
    }
}

void AWorldMapHud::PopupPlayerTownWidget( UTown* town )
{
    auto widget = this->GetPlayerTownWidget();
    if( !widget )
    {
        return;
    }
    this->PopupWidget( widget );
    widget->SetTown( town );
}

void AWorldMapHud::PopupHostileTownWidget( UTown* town )
{
    auto widget = this->GetHostileTownWidget();
    if( !widget )
    {
        return;
    }
    this->PopupWidget( widget );
    widget->SetTown( town );
}

UShowTownWidget* AWorldMapHud::GetPlayerTownWidget()
{
    if( !this->m_widget_town_player && this->playertownClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_town_player = Cast<UShowTownWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->playertownClass, "Player town shower" ) );
    }
    return this->m_widget_town_player;
}

UShowTownWidget* AWorldMapHud::GetHostileTownWidget()
{
    if( !this->m_widget_town_hostile && this->hostiletownClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_town_hostile = Cast<UShowTownWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->hostiletownClass, "Hostile town shower" ) );
    }
    return this->m_widget_town_hostile;
}

USingleWarriorSelectWidget* AWorldMapHud::GetSingleWarriorSelectWidget()
{
    if( !this->m_widget_single_warrior_select && this->singlewarriorClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_single_warrior_select = Cast<USingleWarriorSelectWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->singlewarriorClass, "Single warrior selector" ) );
    }
    return this->m_widget_single_warrior_select;
}

USingleWarriorSelectWidget* AWorldMapHud::PopupSingleWarriorSelector()
{
    auto widget = this->GetSingleWarriorSelectWidget();
    if( widget )
    {
        this->PopupWidget( widget );
    }
    return widget;
}
