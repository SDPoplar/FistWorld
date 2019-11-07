// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WorldMapViewer.generated.h"

UCLASS()
class FISTWORLD_API AWorldMapViewer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWorldMapViewer();

    UFUNCTION( BlueprintCallable )
    void PointTo( AActor* target );

    UFUNCTION( BlueprintCallable )
    void MoveTo( FVector target );

    void ResetCamera( void );
    void ZoomCamera( float volume );
    void MoveForward( float volume );
    void MoveRight( float volume );

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY( EditDefaultsOnly, Category=Camera )
    class USpringArmComponent* m_comp_camera_arm;
    UPROPERTY( EditDefaultsOnly, Category=Camera )
    class UCameraComponent* m_comp_camera;
    UPROPERTY( EditDefaultsOnly, Category=Movement )
    class UMoveWorldViewerComponent* m_comp_move;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
