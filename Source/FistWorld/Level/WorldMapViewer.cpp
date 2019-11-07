// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMapViewer.h"
#include "Camera/CameraComponent.h"
#include "Gameframework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "MoveWorldViewerComponent.h"

// Sets default values
AWorldMapViewer::AWorldMapViewer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    this->bCanBeDamaged = false;
    this->m_comp_camera_arm = CreateDefaultSubobject<USpringArmComponent>( TEXT( "Camera Arm" ) );
    RootComponent = this->m_comp_camera_arm;
    this->m_comp_camera_arm->SetRelativeRotation( FRotator( -45.0f, 0, 0 ) );
    this->m_comp_camera = CreateDefaultSubobject<UCameraComponent>( TEXT( "Camera" ) );
    this->m_comp_camera->SetupAttachment( this->m_comp_camera_arm );
    this->m_comp_camera->SetRelativeRotation( FRotator( 0 ) );
    this->ResetCamera();

    this->m_comp_move = CreateDefaultSubobject<UMoveWorldViewerComponent>( TEXT( "Movement" ) );
    this->m_comp_move->SetUpdatedComponent( RootComponent );
}

// Called when the game starts or when spawned
void AWorldMapViewer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldMapViewer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    this->m_comp_move->MoveTick();
}

// Called to bind functionality to input
void AWorldMapViewer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    UE_LOG( LogTemp, Display, TEXT( "Binding key map" ) );

    InputComponent->BindAxis( "MoveForward", this, &AWorldMapViewer::MoveForward );
    InputComponent->BindAxis( "MoveRight", this, &AWorldMapViewer::MoveRight );
    InputComponent->BindAxis( "ZoomCamera", this, &AWorldMapViewer::ZoomCamera );

    InputComponent->BindAction( "ResetCamera", IE_Released, this, &AWorldMapViewer::ResetCamera );
}

void AWorldMapViewer::PointTo( AActor* target )
{
    this->MoveTo( target->GetActorLocation() );
}

void AWorldMapViewer::MoveTo( FVector target )
{
    this->m_comp_move->StartMove( target, 30 );
}

void AWorldMapViewer::MoveForward( float volume )
{
    auto direction = this->m_comp_move->GetActorLocation().ForwardVector * volume;
    this->m_comp_move->AddInputVector( direction );
}

void AWorldMapViewer::MoveRight( float volume )
{
    auto direction = this->m_comp_move->GetActorLocation().RightVector * volume;
    this->m_comp_move->AddInputVector( direction );
}

void AWorldMapViewer::ZoomCamera( float volume )
{
    float change = volume * 100;
    if( (change < 0) && (this->m_comp_camera_arm->TargetArmLength + change < 0) )
    {
        return;
    }
    if( (change > 0) && (this->m_comp_camera_arm->TargetArmLength + change > 800) )
    {
        return;
    }
    this->m_comp_camera_arm->TargetArmLength += change;
}

void AWorldMapViewer::ResetCamera( void )
{
    this->m_comp_camera_arm->TargetArmLength = 200;
}
