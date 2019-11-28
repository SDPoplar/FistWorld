// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TickAfterTurnOn.h"
#include "FightReporter.generated.h"

UCLASS()
class FISTWORLD_API AFightReporter : public AActor, public TickAfterTurnOn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightReporter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
