// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ListView.h"
#include "WarriorListView.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UWarriorListView : public UListView
{
	GENERATED_BODY()
	
public:
    UWarriorListView( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    UFUNCTION( BlueprintCallable )
    bool ToggleWarriorSelection( UObject* item );

    UFUNCTION( BlueprintCallable )
    bool HasWarriorSelected() const noexcept;

    bool IsWarriorSelected( int warriorId ) const noexcept;
    void Clear();

    TArray<class UWarrior*> GetSelectedWarriors();

protected:
    TArray<int> m_arr_sel;
};
