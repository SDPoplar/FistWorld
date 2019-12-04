// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IUserObjectListEntry.h"
#include "Story/Warrior.h"
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
    FLinearColor GetWarriorGradeColor() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool BindWarriorIns( UObject* warrior );

    UFUNCTION( BlueprintCallable )
    EWarriorType GetWarriorType() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetWarriorName() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetWarriorStrong() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetWarriorStrongTooltip() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetWarriorIntel() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetWarriorIntelTooltip() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetWarriorLevel() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetWarriorLevelTooltip() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetSoldierNum() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetSoldierNumTooltip() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool IsWarriorBinded() const noexcept;

    UWarriorIns* m_warrior;
};
