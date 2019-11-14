// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IUserObjectListEntry.h"
#include "WarriorSelectorItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UWarriorSelectorItemWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
public:

protected:
    UFUNCTION( BlueprintImplementableEvent, Category = ObjectListEntry )
    void OnListItemObjectSet( UObject* ListItemObject );

    UFUNCTION( BlueprintCallable )
    bool BindWarriorIns( UObject* warrior );

    UFUNCTION( BlueprintCallable )
    FText GetWarriorName() const;

    class UWarriorIns* m_warrior;
};
