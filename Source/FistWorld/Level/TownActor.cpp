// Fill out your copyright notice in the Description page of Project Settings.


#include "TownActor.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Story/Town.h"
#include "Components/WidgetComponent.h"
#include "Widget/ShowTownWidget.h"

// Sets default values
ATownActor::ATownActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    this->bCanBeDamaged = false;

    this->m_mesh_town = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "Mesh" ) );
    RootComponent = this->m_mesh_town;
    //  this->m_mesh_town->SetupAttachment( RootComponent );

    static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh( TEXT( "/Game/Levels/Res_lv_World/town_01" ) );
    if( mesh.Succeeded() )
    {
        this->m_mesh_town->SetStaticMesh( mesh.Object );
    }
    this->m_mesh_flag = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "FlagMesh" ) );
    static ConstructorHelpers::FObjectFinder<UStaticMesh> flagmesh( TEXT( "/Game/Levels/Res_lv_World/static_mesh_flag" ) );
    if( flagmesh.Succeeded() )
    {
        this->m_mesh_flag->SetStaticMesh( flagmesh.Object );
    }
    this->m_mesh_flag->SetupAttachment( RootComponent );
    this->m_mesh_flag->SetRelativeLocation( FVector( 0, 0, 80 ) );
    this->m_mesh_flag->SetRelativeRotation( FQuat( 0, 0, 45, 0 ) );
    this->m_particle_hover_circle = CreateDefaultSubobject<UParticleSystemComponent>( TEXT( "Hover circle" ) );
    this->m_particle_hover_circle->SetupAttachment( RootComponent );
    this->m_particle_hover_circle->SetVisibility( false );
    this->m_particle_hover_circle->SetRelativeLocation( FVector( 0, 0, 10 ) );
    static ConstructorHelpers::FObjectFinder<UParticleSystem> hovercircle( TEXT( "/Game/Levels/Res_lv_World/HoverCircle/Particle_HoverCircle" ) );
    if( hovercircle.Succeeded() )
    {
        this->m_particle_hover_circle->SetTemplate( hovercircle.Object );
    }

    this->m_widget_summary = CreateDefaultSubobject<UWidgetComponent>( TEXT( "Town summary" ) );
    this->m_widget_summary->SetupAttachment( RootComponent );
    static ConstructorHelpers::FClassFinder<UShowTownWidget> townsummary( TEXT( "/Game/Levels/Res_lv_World/Widget_World_TownHoverSummary" ) );
    if( townsummary.Succeeded() )
    {
        this->m_widget_summary->SetWidgetClass( townsummary.Class );
    }
    this->m_o_town = nullptr;
}

// Called when the game starts or when spawned
void ATownActor::BeginPlay()
{
	Super::BeginPlay();
    
    if( !this->GetTown() )
    {
        return;
    }
    //  this->m_widget_summary->bindtown
    for( auto item : this->m_can_arrive )
    {
        this->GetTown()->AppendArrive( item->GetTown() );
    }
}

// Called every frame
void ATownActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if( this->GetTown() && this->GetTown()->OwnByKingdom() )
    {
        this->m_mesh_flag->SetVisibility( true );
        auto m = this->GetFlagMaterial( UKingdom::OwnByPlayer( this->GetTown()->GetKingdomId() ) );
        this->m_mesh_flag->SetMaterial( 1, m );
    }
    else
    {
        this->m_mesh_flag->SetVisibility( false );
    }
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
    auto hud = this->GetTown()->OwnByPlayer() ? pc->GetWorldMapHud() : nullptr;
    if( hud )
    {
        hud->ShowTownInfo( this->GetTown() );
    }
}

UTown* ATownActor::GetTown()
{
    if( !this->m_o_town )
    {
        auto gi = UFistWorldInstance::GetInstance( this );
        if( gi )
        {
            this->m_o_town = gi->FindTown( this->m_bind_town );
        }
    }
    return this->m_o_town;
}

UStaticMeshComponent* ATownActor::GetFlagMesh() const noexcept
{
    return this->m_mesh_flag;
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

    if( this->m_widget_summary && this->m_widget_summary->IsValidLowLevelFast() )
    {
        this->m_widget_summary->SetVisibility( hover );
    }
}
