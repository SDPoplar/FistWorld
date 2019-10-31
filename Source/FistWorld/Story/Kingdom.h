// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
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

    UFUNCTION( BlueprintCallable )
    bool IsPlayerKingdom() const;

    //  bool LoadById()

protected:
    bool m_b_own_by_player;

    static UDataTable* g_lib;
};
