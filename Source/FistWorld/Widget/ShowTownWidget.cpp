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
