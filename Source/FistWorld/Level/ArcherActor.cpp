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
}
