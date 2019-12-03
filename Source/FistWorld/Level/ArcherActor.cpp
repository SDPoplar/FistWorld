// Copyright 2019

#include "ArcherActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AArcherActor::AArcherActor() : AFightActor()
{
    ConstructorHelpers::FObjectFinder<USkeletalMesh> bodymesh( TEXT( "/Game/Levels/Res_lv_Fight/WarriorMeshes/Mesh_Warrior_Archer" ) );
    if( bodymesh.Succeeded() )
    {
        this->m_mesh_warrior->SetSkeletalMesh( bodymesh.Object );
    }
    this->m_f_attack_range = 800;
    this->m_f_attack_cd = 1.5f;
}

float AArcherActor::GetAttackMagnification( EWarriorType targetType, float targetDistance ) const noexcept
{
    float healthPlus = (this->m_f_current_health / this->m_f_max_health > 0.8) ? 2.0 : 1.0;
    switch( targetType )
    {
    case EWarriorType::RIDER:
        return 0.8f * healthPlus;
    case EWarriorType::SHIELD:
        return 0.6f * healthPlus;
    default:
        return 1.0f * healthPlus;
    }
}
