// Fill out your copyright notice in the Description page of Project Settings.


#include "TownActor.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
//  #include "Components/WidgetComponent.h"

// Sets default values
ATownActor::ATownActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    this->bCanBeDamaged = false;

    this->m_mesh_town = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "Mesh" ) );
    RootComponent = this->m_mesh_town;
    //  this->m_mesh_town->SetupAttachment( RootComponent );

    static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh( TEXT( "/Game/Levels/Res_lv_world/town_01" ) );
    if( mesh.Succeeded() )
    {
        this->m_mesh_town->SetStaticMesh( mesh.Object );
    }
    this->m_particle_hover_circle = CreateDefaultSubobject<UParticleSystemComponent>( TEXT( "Hover circle" ) );
    this->m_particle_hover_circle->SetupAttachment( RootComponent );
    this->m_particle_hover_circle->SetVisibility( false );
    this->m_particle_hover_circle->SetRelativeLocation( FVector( 0, 0, 10 ) );
    static ConstructorHelpers::FObjectFinder<UParticleSystem> hovercircle( TEXT( "/Game/Levels/Res_lv_world/HoverCircle/Particle_HoverCircle" ) );
    if( hovercircle.Succeeded() )
    {
        this->m_particle_hover_circle->SetTemplate( hovercircle.Object );
    }

    this->m_o_town = nullptr;
}

// Called when the game starts or when spawned
void ATownActor::BeginPlay()
{
	Super::BeginPlay();
    this->m_o_town = UFistWorldInstance::GetInstance( this )->FindTown( this->m_bind_town );
}

// Called every frame
void ATownActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UObject* ATownActor::SelfPointer()
{
    return this;
}

void ATownActor::SelectByPlayer()
{
    auto pc = AWorldMapController::GetInstance( this );
    if( !pc )
    {
        return;
    }
    if( pc->HasTaskSelectingTown() )
    {
        pc->SetTaskSelectingTown( this );
        return;
    }
    auto hud = pc->GetWorldMapHud();
    if( hud )
    {
        hud->ShowTownInfo( this );
    }
}

UTown* ATownActor::GetTown()
{
    return this->m_o_town;
}

UParticleSystemComponent* ATownActor::GetHoverCircle() const
{
    return this->m_particle_hover_circle;
}

void ATownActor::SetHover( bool hover )
{
    if( this->m_particle_hover_circle && this->m_particle_hover_circle->IsValidLowLevelFast() )
    {
        this->m_particle_hover_circle->SetVisibility( hover );
    }
}
