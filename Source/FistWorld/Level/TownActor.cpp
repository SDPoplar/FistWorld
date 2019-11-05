// Fill out your copyright notice in the Description page of Project Settings.


#include "TownActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
//  #include "Components/WidgetComponent.h"

// Sets default values
ATownActor::ATownActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    this->m_mesh_town = CreateDefaultSubobject<UStaticMeshComponent>( TEXT( "Mesh" ) );
    this->m_mesh_town->SetupAttachment( RootComponent );

    static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh( TEXT( "/Game/Levels/Res_lv_world/town_01" ) );
    if( mesh.Succeeded() )
    {
        this->m_mesh_town->SetStaticMesh( mesh.Object );
    }
}

// Called when the game starts or when spawned
void ATownActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATownActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

