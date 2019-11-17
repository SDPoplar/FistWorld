// Fill out your copyright notice in the Description page of Project Settings.

#include "WarriorSelectorItemWidget.h"
#include "Story/Warrior.h"

bool UWarriorSelectorItemWidget::BindWarriorIns( UObject* ins )
{
    auto warrior = Cast<UWarriorIns>( ins );
    if( !warrior )
    {
        return false;
    }
    this->m_warrior = warrior;
    return true;
}

FText UWarriorSelectorItemWidget::GetWarriorName() const
{
    /*
    return FText::FromString( (this->m_warrior && this->m_warrior->IsValidLowLevelFast())
        ? this->m_warrior->GetWarriorName() : FString( "-" ) );
        */
    return FText::FromString( (this->m_warrior && this->m_warrior->IsValidLowLevelFast())
        ? []( UWarriorIns* warrior )->FString {
            FString ret = warrior->GetWarriorName();
            char buff[ 256 ];
            sprintf_s( buff, 256, "[LV:%d] Strong: %d, Intel: %d, Soldier: %d", warrior->GetWarriorLevel(),
                warrior->GetStrong(), warrior->GetIntel(), warrior->GetSoldierNumber() );
            ret += buff;
            return ret;
        }( this->m_warrior ) : FString( "-" ) );
}
