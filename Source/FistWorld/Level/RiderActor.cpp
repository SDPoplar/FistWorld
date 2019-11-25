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
}
