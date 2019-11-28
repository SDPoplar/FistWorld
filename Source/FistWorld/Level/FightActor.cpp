// Copyright 2019

#include "FightActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Story/Kingdom.h"
#include "Level/ArcherActor.h"
#include "Level/ShieldActor.h"
#include "Level/RiderActor.h"
#include "FightReporter.h"

// Sets default values
AFightActor::AFightActor() : TickAfterTurnOn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    this->m_mesh_warrior = CreateDefaultSubobject<USkeletalMeshComponent>( "Warrior body" );
    RootComponent = this->m_mesh_warrior;
}

// Called when the game starts or when spawned
void AFightActor::BeginPlay()
{
	AActor::BeginPlay();
	
}

// Called every frame
void AFightActor::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);
    CHECK_TICK_TURNON_NORET;
    this->FighterTick( DeltaTime );
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

void AFightActor::BindReporter( AFightReporter* reporter )
{
    this->m_o_reporter = reporter;
}

void AFightActor::ReportDeath()
{
    //  this->m_o_reporter
}
