// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "CommonMapViewer.generated.h"

UCLASS()
class FISTWORLD_API ACommonMapViewer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACommonMapViewer();

    void ResetCamera( void );
    void SaveCameraOrigin();
    void ZoomCamera( float volume );
    void MoveForward( float volume );
    void MoveRight( float volume );

    UFUNCTION( BlueprintCallable )
    void PointTo( AActor* target );

    template<class T>
    static T* Get( UObject* getter )
    {
        return Cast<T>( UGameplayStatics::GetPlayerPawn( getter, 0 ) );
    }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    class USphereComponent* m_comp_sphere;
    class USpringArmComponent* m_comp_camera_arm;
    class UCameraComponent* m_comp_camera;
    class UFloatingPawnMovement* m_comp_move;

    float m_f_def_arm_len;
    FVector m_vec_camera_origin;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
