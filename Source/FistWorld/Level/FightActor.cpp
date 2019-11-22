// Copyright 2019

#include "FightActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Story/Kingdom.h"
#include "Level/ArcherActor.h"
#include "Level/ShieldActor.h"
#include "Level/RiderActor.h"

// Sets default values
AFightActor::AFightActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    this->m_mesh_warrior = CreateDefaultSubobject<USkeletalMeshComponent>( "Warrior body" );
    RootComponent = this->m_mesh_warrior;
}

// Called when the game starts or when spawned
void AFightActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFightActor::LoadWarrior( UWarrior* warrior )
{
}

AFightActor* AFightActor::SpawnWarrior( UWarrior* warrior, UWorld* inWorld )
{
    AFightActor* actor = nullptr;
    switch( warrior->GetWarriorType() )
    {
    case EWarriorType::SHIELD:
        actor = inWorld->SpawnActor<AShieldActor>();
        break;
    case EWarriorType::RIDER:
        actor = inWorld->SpawnActor<ARiderActor>();
        break;
    case EWarriorType::ARCHER:
        actor = inWorld->SpawnActor<AArcherActor>();
        break;
    default:
        return nullptr;
    }
    actor->LoadWarrior( warrior );
    return actor;
}
