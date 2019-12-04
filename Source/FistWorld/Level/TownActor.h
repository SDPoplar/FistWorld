// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TownActor.generated.h"

UCLASS()
class FISTWORLD_API ATownActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATownActor( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    UFUNCTION( BlueprintCallable )
    void SelectByPlayer();

    class UTown* GetTown();

    UFUNCTION( BlueprintCallable )
    class UParticleSystemComponent* GetHoverCircle() const;

    UFUNCTION( BlueprintCallable )
    void SetHover( bool hover );

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UPROPERTY( EditAnywhere, Category = "Data" )
    int m_bind_town;

    UPROPERTY( EditAnywhere, Category = "Data" )
    TArray<ATownActor*> m_can_arrive;

    UPROPERTY( EditDefaultsOnly )
    class UStaticMeshComponent* m_mesh_town;
    class UParticleSystemComponent* m_particle_hover_circle;
    class UWidgetComponent* m_widget_summary;
    class UTownNamePanelComponent* m_comp_namepanel;
    class UTown* m_o_town;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    void BeginMouseOver();

    UFUNCTION()
    void EndMouseOver();
};
