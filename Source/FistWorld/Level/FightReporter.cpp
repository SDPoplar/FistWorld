// Copyright 2019


#include "FightReporter.h"

// Sets default values
AFightReporter::AFightReporter() : TickAfterTurnOn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFightReporter::BeginPlay()
{
	AActor::BeginPlay();
	
}

// Called every frame
void AFightReporter::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);
    CHECK_TICK_TURNON_NORET;

}
