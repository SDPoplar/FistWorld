// Fill out your copyright notice in the Description page of Project Settings.


#include "ShowTownWidget.h"
#include "Engine/Texture2D.h"
#include "FistWorldInstance.h"
#include "Story/Town.h"
#include "Story/Kingdom.h"

#include "TextBlock.h"
#include "Image.h"

void UShowTownWidget::SetTown( UTown* town )
{
    this->m_town = town;
    if( !this->m_shower_town_name || !this->m_shower_town_name->IsValidLowLevelFast() )
    {
        return;
    }
    this->m_shower_town_name->SetText( FText::FromString( town->GetTownName() ) );
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->FindKingdom( town->GetKingdomId() ) : nullptr;
    if( kingdom )
    {
        this->m_shower_kingdom_name->SetText( FText::FromString( kingdom->GetKingdomName() ) );
        this->m_shower_kingdom_logo->SetBrushFromTexture( kingdom->GetLogo() );
    }

    if( !this->m_shower_agriculture || !this->m_shower_agriculture->IsValidLowLevelFast() )
    {
        return;
    }
    this->m_shower_agriculture->SetText( FText::FromString( town->GetAgricultureDevelopment().ToString() ) );
    this->m_shower_business->SetText( FText::FromString( town->GetBusinessDevelopment().ToString() ) );
    char volume[ 12 ];
    sprintf_s( volume, 12, "%d", town->GetFood() );
    this->m_shower_food->SetText( FText::FromString( volume ) );
    sprintf_s( volume, 12, "%d", town->GetMoney() );
    this->m_shower_money->SetText( FText::FromString( volume ) );
}

FString UShowTownWidget::GetTownName()
{
    return this->m_town ? this->m_town->GetTownName() : "";
}

UTexture2D* UShowTownWidget::GetKingdomLogo()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->FindKingdom( this->m_town ? this->m_town->GetKingdomId() : 0 ) : nullptr;
    return kingdom ? kingdom->GetLogo() : nullptr;
}

void UShowTownWidget::RegistBaseShowers( UTextBlock* townNameShower, UTextBlock* kingdomNameShower, UImage* kingdomLogoShower )
{
    this->m_shower_town_name = townNameShower;
    this->m_shower_kingdom_name = kingdomNameShower;
    this->m_shower_kingdom_logo = kingdomLogoShower;
}

void UShowTownWidget::RegistDevelopShower( UTextBlock* agricultureShower, UTextBlock* businessShower, UTextBlock* foodShower, UTextBlock* moneyShower )
{
    this->m_shower_agriculture = agricultureShower;
    this->m_shower_business = businessShower;
    this->m_shower_food = foodShower;
    this->m_shower_money = moneyShower;
}
