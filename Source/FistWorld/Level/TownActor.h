// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldMapElement.h"
#include "TownActor.generated.h"

UCLASS()
class FISTWORLD_API ATownActor : public AActor, public WorldMapElement
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATownActor();

    UFUNCTION( BlueprintCallable )
    void SelectByPlayer();

    class UTown* GetTown();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual UObject* SelfPointer() override;

    UPROPERTY( EditAnywhere, Category = "Data" )
    int m_bind_town;

    UPROPERTY( EditAnywhere, Category = "Community" )
    TArray<ATownActor*> m_can_arrive;

    class UStaticMeshComponent* m_mesh_town;
    class UTown* m_o_town;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
