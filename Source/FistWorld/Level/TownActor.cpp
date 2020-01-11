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
#include "Components/TownNamePanelComponent.h"

// Sets default values
ATownActor::ATownActor( const FObjectInitializer& ObjectInitializer ) : AActor( ObjectInitializer ), m_o_town( nullptr )
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    this->SetCanBeDamaged( false );

    this->m_mesh_town = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "Mesh" ) );
    RootComponent = this->m_mesh_town;
    //  this->m_mesh_town->SetupAttachment( RootComponent );

    static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh( TEXT( "/Game/Levels/Res_lv_World/town_01" ) );
    if( mesh.Succeeded() )
    {
        this->m_mesh_town->SetStaticMesh( mesh.Object );
    }
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

    this->m_comp_namepanel = CreateDefaultSubobject<UTownNamePanelComponent>( TEXT( "Town namepanel" ) );
    this->m_comp_namepanel->SetupAttachment( RootComponent );
    this->m_comp_namepanel->SetRelativeLocation( FVector( 0, 0, 100 ) );


    //  Bind events

    FScriptDelegate cursor_hover, cursor_unhover, cursor_click;
    cursor_hover.BindUFunction( this, FName( "BeginMouseOver" ) );
    this->OnBeginCursorOver.Add( cursor_hover );
    cursor_unhover.BindUFunction( this, FName( "EndMouseOver" ) );
    this->OnEndCursorOver.Add( cursor_unhover );
    cursor_click.BindUFunction( this, FName( "SelectByPlayer" ) );
    this->OnClicked.Add( cursor_click );
}

// Called when the game starts or when spawned
void ATownActor::BeginPlay()
{
	Super::BeginPlay();
    UTown* town = this->GetTown();
    if( !town )
    {
        return;
    }
    //  this->m_widget_summary->bindtown
    for( auto item : this->m_can_arrive )
    {
        town->AppendArrive( item->GetTown() );
    }
}

// Called every frame
void ATownActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

void ATownActor::BeginMouseOver()
{
    this->SetHover( true );
}

void ATownActor::EndMouseOver()
{
    this->SetHover( false );
}
