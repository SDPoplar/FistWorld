// Fill out your copyright notice in the Description page of Project Settings.

#include "KingdomSummaryWidget.h"
#include "Story/Kingdom.h"
#include "Engine/Texture2D.h"
#include "TextBlock.h"
#include "Controllers/CommonMapController.h"
#include "FistWorldInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Tasks/ExcutableTask.h"

UKingdomSummaryWidget* UKingdomSummaryWidget::Create( TSubclassOf<UKingdomSummaryWidget> clsName, UWorld* world, FName widgetName )
{
    auto widget = UUserWidget::CreateWidgetInstance( *world, clsName, widgetName );
    return Cast<UKingdomSummaryWidget>( widget );
}

UKingdom* UKingdomSummaryWidget::BindKingdom( UKingdom* kingdom )
{
    this->m_o_kingdom = kingdom;
    if( !kingdom )
    {
        UE_LOG( LogTemp, Error, TEXT( "Invalid kingdom binded" ) );
    }
    return this->m_o_kingdom;
}

UTexture2D* UKingdomSummaryWidget::GetKingdomLogo() const noexcept
{
    return this->m_o_kingdom ? this->m_o_kingdom->GetLogo() : nullptr;
}

FString UKingdomSummaryWidget::GetKingdomName() const noexcept
{
    return this->m_o_kingdom ? this->m_o_kingdom->GetKingdomName() : FString( "" );
}

ESlateVisibility UKingdomSummaryWidget::PlayerHasTask() const
{
    if( !this->m_o_task_shower || !this->m_o_task_shower->IsValidLowLevelFast() )
    {
        return ESlateVisibility::Collapsed;
    }
    auto pc = Cast<ACommonMapController>( UGameplayStatics::GetPlayerController( this, 0 ) );
    auto task = ( pc && pc->HasTask() ) ? pc->GetTask() : nullptr;
    if( !task || !task->NeedDisplayStep() )
    {
        return ESlateVisibility::Collapsed;
    }
    if( this->m_o_task_shower && this->m_o_task_shower->IsValidLowLevelFast()
        && (this->m_o_task_shower->GetVisibility() == ESlateVisibility::Visible) )
    {
        this->m_o_task_shower->SetText( FText::FromString( task->GetStepDescribe() ) );
    }
    return ESlateVisibility::Visible;
}

void UKingdomSummaryWidget::BindTaskShower( UTextBlock* taskShower )
{
    this->m_o_task_shower = taskShower;
}

FText UKingdomSummaryWidget::GetPlayerTownNum() const noexcept
{
    auto gi = UFistWorldInstance::GetInstance( this );
    char num[ 8 ];
    sprintf_s( num, 8, "%d", gi ? gi->CountPlayerTown() : 0 );
    return FText::FromString( num );
}

FText UKingdomSummaryWidget::GetPlayerWarriorNum() const noexcept
{
    auto gi = UFistWorldInstance::GetInstance( this );
    char num[ 8 ];
    sprintf_s( num, 8, "%d", gi ? gi->CountPlayerWarrior() : 0 );
    return FText::FromString( num );
}

FText UKingdomSummaryWidget::GetPlayerKingdomFood() const noexcept
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetMyKingdom() : nullptr;
    char num[ 12 ];
    sprintf_s( num, 12, "%d", kingdom ? kingdom->GetFood() : 0 );
    return FText::FromString( num );
}

FText UKingdomSummaryWidget::GetPlayerKingdomMoney() const noexcept
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetMyKingdom() : nullptr;
    char num[ 12 ];
    sprintf_s( num, 12, "%d", kingdom ? kingdom->GetMoney() : 0 );
    return FText::FromString( num );
}
