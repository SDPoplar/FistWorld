// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Story/Warrior.h"
#include <map>
#include "FightActor.generated.h"

UCLASS()
class FISTWORLD_API AFightActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightActor();

    virtual void LoadWarrior( UWarrior* warrior );
    static AFightActor* SpawnWarrior( UWarrior* warrior, UWorld* inWorld );

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    class USkeletalMeshComponent* m_mesh_warrior;

    TSubclassOf<AFightActor> archarClass, riderClass, shieldClass;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
