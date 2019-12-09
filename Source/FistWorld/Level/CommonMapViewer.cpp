// Copyright 2019

#include "CommonMapViewer.h"
#include "Camera/CameraComponent.h"
#include "Gameframework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ACommonMapViewer::ACommonMapViewer() : m_f_def_arm_len( 400.0f ), m_vec_camera_origin( FVector( 0 ) )
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    this->bCanBeDamaged = false;
    RootComponent = CreateDefaultSubobject<USceneComponent>( "Root comp" );
    this->m_comp_sphere = CreateDefaultSubobject<USphereComponent>( "Sphere comp" );
    this->m_comp_sphere->SetSphereRadius( 50.0f );
    this->m_comp_sphere->SetupAttachment( RootComponent );
    this->m_comp_camera_arm = CreateDefaultSubobject<USpringArmComponent>( TEXT( "Camera Arm" ) );
    this->m_comp_camera_arm->SetupAttachment( RootComponent );
    this->m_comp_camera_arm->SetRelativeRotation( FRotator( -45.0f, 0, 0 ) );
    this->m_comp_camera = CreateDefaultSubobject<UCameraComponent>( TEXT( "Camera" ) );
    this->m_comp_camera->SetupAttachment( this->m_comp_camera_arm );
    this->m_comp_camera->SetRelativeRotation( FRotator( 0 ) );

    this->m_comp_move = CreateDefaultSubobject<UFloatingPawnMovement>( TEXT( "Movement" ) );
    this->m_comp_move->SetUpdatedComponent( RootComponent );
}

// Called when the game starts or when spawned
void ACommonMapViewer::BeginPlay()
{
	Super::BeginPlay();
    this->SaveCameraOrigin();
    this->ResetCamera();
}

// Called every frame
void ACommonMapViewer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACommonMapViewer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAction( "ResetCamera", IE_Released, this, &ACommonMapViewer::ResetCamera );
}

void ACommonMapViewer::SaveCameraOrigin()
{
    this->m_vec_camera_origin = this->GetActorLocation();
}

void ACommonMapViewer::PointTo( AActor* target )
{
    //  this->MoveTo( target->GetActorLocation() );
    auto targetLocation = target->GetActorLocation();
    targetLocation.Z += 200;
    this->SetActorLocation( targetLocation );
}

void ACommonMapViewer::MoveForward( float volume )
{
    auto direction = this->m_comp_move->GetActorLocation().ForwardVector * volume;
    this->m_comp_move->AddInputVector( direction );
}

void ACommonMapViewer::MoveRight( float volume )
{
    auto direction = this->m_comp_move->GetActorLocation().RightVector * volume;
    this->m_comp_move->AddInputVector( direction );
}

void ACommonMapViewer::ZoomCamera( float volume )
{
    float change = volume * 100;
    if( (change < 0) && (this->m_comp_camera_arm->TargetArmLength + change < 0) )
    {
        return;
    }
    if( (change > 0) && (this->m_comp_camera_arm->TargetArmLength + change > 1600) )
    {
        return;
    }
    this->m_comp_camera_arm->TargetArmLength += change;
}

void ACommonMapViewer::ResetCamera( void )
{
    this->SetActorLocation( this->m_vec_camera_origin );
    this->m_comp_camera_arm->TargetArmLength = this->m_f_def_arm_len;
}
