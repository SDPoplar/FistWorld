// Copyright 2019

#include "FightLevelScript.h"

void AFightLevelScript::ResetBothBirthPoint( void )
{
    this->m_n_bp_index_attacker = 0;
    this->m_n_bp_index_defencer = 0;
}

FVector AFightLevelScript::GetAttackerStartPointLocation() const noexcept
{
    return this->GetAttackStartPoint()->GetActorLocation();
}

FVector AFightLevelScript::GetDefencerStartPointLocation() const noexcept
{
    return this->GetDefenceStartPoint()->GetActorLocation();
}

FVector AFightLevelScript::GetAttackerNextBirthPoint() noexcept
{
    return this->GetBirthPoint( this->GetAttackStartPoint()->GetActorLocation(), this->m_n_bp_index_attacker++ );
}

FVector AFightLevelScript::GetDefencerNextBirthPoint() noexcept
{
    return this->GetBirthPoint( this->GetDefenceStartPoint()->GetActorLocation(), this->m_n_bp_index_defencer++ );
}

FVector AFightLevelScript::GetBirthPoint( FVector base, int index ) const noexcept
{
    FVector ret = base;
    ret.Y += ( (index % 2 ? 1 : -1) * (index * 100) );
    return ret;
}