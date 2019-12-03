// Copyright 2019

#include "RiderActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SkeletalMeshComponent.h"

ARiderActor::ARiderActor() : AFightActor()
{
    ConstructorHelpers::FObjectFinder<USkeletalMesh> bodymesh( TEXT( "/Game/Levels/Res_lv_Fight/WarriorMeshes/Mesh_Warrior_Rider" ) );
    if( bodymesh.Succeeded() )
    {
        this->m_mesh_warrior->SetSkeletalMesh( bodymesh.Object );
    }
    this->m_f_attack_range = 250;
    this->m_f_attack_cd = 0.8f;
}

float ARiderActor::GetAttackMagnification( EWarriorType targetType, float targetDistance ) const noexcept
{
    switch( targetType )
    {
    case EWarriorType::ARCHER:
        return 1.5f;
    case EWarriorType::SHIELD:
        return 0.8f;
    default:
        return 1.0f;
    }
}
