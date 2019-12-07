// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Controllers/CommonMapController.h"
#include "ViewportEdgeWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UViewportEdgeWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UViewportEdgeWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    UPROPERTY( EditAnywhere )
    TArray<EViewportEdge> bindedEdgeSide;

protected:
    UFUNCTION( BlueprintCallable )
    bool CanMoveTowads() const noexcept;

    UFUNCTION( BlueprintCallable )
    void TurnOnMove();
    
    UFUNCTION( BlueprintCallable )
    void TurnOffMove();

    UFUNCTION( BlueprintCallable )
    void MoveIfTurnedOn();

    ACommonMapController* GetController() const noexcept;

    bool m_b_move_flag;
};
