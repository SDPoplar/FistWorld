// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMapViewer.h"
#include "Camera/CameraComponent.h"
#include "Gameframework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "MoveWorldViewerComponent.h"

// Sets default values
AWorldMapViewer::AWorldMapViewer() : ACommonMapViewer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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
}

// Called to bind functionality to input
void AWorldMapViewer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
