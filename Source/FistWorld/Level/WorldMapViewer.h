// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonMapViewer.h"
#include "WorldMapViewer.generated.h"

UCLASS()
class FISTWORLD_API AWorldMapViewer : public ACommonMapViewer
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWorldMapViewer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
