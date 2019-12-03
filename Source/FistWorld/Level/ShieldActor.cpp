// Copyright 2019

#include "ShieldActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SkeletalMeshComponent.h"

AShieldActor::AShieldActor() : AFightActor()
{
    ConstructorHelpers::FObjectFinder<USkeletalMesh> bodymesh( TEXT( "/Game/Levels/Res_lv_Fight/WarriorMeshes/Mesh_Warrior_Shield" ) );
    if( bodymesh.Succeeded() )
    {
        this->m_mesh_warrior->SetSkeletalMesh( bodymesh.Object );
    }
    this->m_f_attack_range = 220;
}

float AShieldActor::GetAttackMagnification( EWarriorType targetType, float targetDistance ) const noexcept
{
    return 0.8;
}
