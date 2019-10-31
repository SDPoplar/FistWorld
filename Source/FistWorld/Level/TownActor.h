// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "TownActor.generated.h"

UCLASS()
class FISTWORLD_API ATownActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATownActor();

    UPROPERTY( EditAnywhere, Category = "Community" )
    TArray<ATownActor*> m_can_arrive;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UStaticMeshComponent* m_mesh_town;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
