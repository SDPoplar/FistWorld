// Fill out your copyright notice in the Description page of Project Settings.


#include "ShowTownWidget.h"
#include "Engine/Texture2D.h"
#include "FistWorldInstance.h"
#include "Story/Town.h"
#include "Story/Kingdom.h"

void UShowTownWidget::SetTown( UTown* town )
{
    this->m_town = town;
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
