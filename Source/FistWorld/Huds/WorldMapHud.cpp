// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapHud.h"
#include "Widget/KingdomSummaryWidget.h"
#include "Widget/SysMenuWidget.h"
#include "Widget/ShowTownWidget.h"
#include "Widget/SingleWarriorSelectWidget.h"
#include "Widget/MultiWarriorSelectWidget.h"
#include "Widget/TownTransportVolumeWidget.h"
#include "Widget/SoldierNumWidget.h"
#include "Widget/ConfirmBackWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"
#include "FistWorldInstance.h"
//  #include "Level/TownActor.h"
#include "Story/Town.h"

AWorldMapHud::AWorldMapHud() : ACommonMapHud(), m_widget_town_player( nullptr ), m_widget_town_hostile( nullptr ),
    m_widget_transport( nullptr ), m_widget_single_warrior_select( nullptr ), m_widget_multi_warrior_select( nullptr ),
    m_widget_soldier_num( nullptr )
{
    static ConstructorHelpers::FClassFinder<USysMenuWidget> sysmenufinder( TEXT( "/Game/Levels/Res_lv_World/Widget_World_SysMenu" ) );
    sysmenuClass = sysmenufinder.Succeeded() ? sysmenufinder.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UKingdomSummaryWidget> topsummary( TEXT( "/Game/Levels/Res_lv_World/Widget_World_StaticShower" ) );
    topsummaryClass = topsummary.Succeeded() ? topsummary.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UShowTownWidget> playertownwidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_PlayerTown" ) );
    playertownClass = playertownwidget.Succeeded() ? playertownwidget.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UShowTownWidget> hostiletownwidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_HostileTown" ) );
    hostiletownClass = hostiletownwidget.Succeeded() ? hostiletownwidget.Class : nullptr;
    static ConstructorHelpers::FClassFinder<USingleWarriorSelectWidget> singlewarriorwidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_SingleWarriorSelector" ) );
    singlewarriorClass = singlewarriorwidget.Succeeded() ? singlewarriorwidget.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UMultiWarriorSelectWidget> multiwarriorwidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_MultiWarriorSelector" ) );
    multiwarriorClass = multiwarriorwidget.Succeeded() ? multiwarriorwidget.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UTownTransportVolumeWidget> transvolumewidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_TransportVolume" ) );
    transvolumeClass = transvolumewidget.Succeeded() ? transvolumewidget.Class : nullptr;
    static ConstructorHelpers::FClassFinder<USoldierNumWidget> soldiernumwidget( TEXT( "/Game/Levels/Res_lv_World/Widget_World_SoldierNumber" ) );
    soldiernumClass = soldiernumwidget.Succeeded() ? soldiernumwidget.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UConfirmBackWidget> confirmback( TEXT( "/Game/Levels/Res_lv_World/Widget_World_ConfirmBack" ) );
    confirmbackClass = confirmback.Succeeded() ? confirmback.Class : nullptr;
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
    if( town->OwnByPlayer() )
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
        this->m_widget_town_player->AddToViewport( 10 );
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
        this->m_widget_town_hostile->AddToViewport( 10 );
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
        this->m_widget_single_warrior_select->AddToViewport( 20 );
    }
    return this->m_widget_single_warrior_select;
}

UMultiWarriorSelectWidget* AWorldMapHud::GetMultiWarriorSelectWidget()
{
    if( !this->m_widget_multi_warrior_select && this->multiwarriorClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_multi_warrior_select = Cast<UMultiWarriorSelectWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->multiwarriorClass, "Multi warrior selector" ) );
        this->m_widget_multi_warrior_select->AddToViewport( 20 );
    }
    return this->m_widget_multi_warrior_select;
}

USoldierNumWidget* AWorldMapHud::GetSoldierNumWidget()
{
    if( !this->m_widget_soldier_num && this->soldiernumClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_soldier_num = Cast<USoldierNumWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->soldiernumClass, "Soldier num setter" ) );
        this->m_widget_soldier_num->AddToViewport( 20 );
    }
    return this->m_widget_soldier_num;
}

UTownTransportVolumeWidget* AWorldMapHud::GetTransportVolumeWidget()
{
    if( !this->m_widget_transport && this->transvolumeClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_transport = Cast<UTownTransportVolumeWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->transvolumeClass, "Transport volume setter" ) );
        this->m_widget_transport->AddToViewport( 20 );
    }
    return this->m_widget_transport;
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

UMultiWarriorSelectWidget* AWorldMapHud::PopupMultiWarriorSelector()
{
    auto widget = this->GetMultiWarriorSelectWidget();
    if( widget )
    {
        this->PopupWidget( widget );
    }
    return widget;
}

bool AWorldMapHud::PopupTransportVolumeSetter( int maxFood, int maxMoney )
{
    auto widget = this->GetTransportVolumeWidget();
    if( !widget )
    {
        return false;
    }
    this->PopupWidget( widget );
    widget->SetMax( maxFood, maxMoney );
    return true;
}

bool AWorldMapHud::PopupSoldierNumSetter( int max )
{
    auto widget = this->GetSoldierNumWidget();
    if( !widget )
    {
        return false;
    }
    this->PopupWidget( widget );
    widget->SetMax( max );
    return true;
}
