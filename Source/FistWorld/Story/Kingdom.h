// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "FistWorldSave.h"
#include "Kingdom.generated.h"

/*
USTRUCT( BlueprintType )
struct FKingdomInfo : FTableRowBase
{
    int id;
    UTexture2D* logo;
};
*/

/**
 * 
 */
UCLASS()
class FISTWORLD_API UKingdom : public UObject
{
	GENERATED_BODY()
	
public:
    UKingdom();

    bool SetKingdomId( int id, bool loadData = true );
    int GetKingdomId() const;

    UFUNCTION( BlueprintCallable )
    bool IsPlayerKingdom() const;

    UFUNCTION( BlueprintCallable )
    void SetPlayerKingdom( const bool isPlayerKingdom = true );

    int AppendWarrior( class UWarrior* warrior );

protected:
    int m_n_kingdom_id;
    bool m_b_own_by_player;

    TArray<class UWarrior*> m_has_warriors;

    static UDataTable* g_lib;
};
