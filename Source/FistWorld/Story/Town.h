// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Town.generated.h"

USTRUCT( BlueprintType )
struct FTownBaseData : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY( BlueprintReadOnly )
        int id;

    UPROPERTY( BlueprintReadOnly )
        FString name;
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTown : public UObject
{
    GENERATED_BODY()

public:
    UTown();

    bool SetTownId( int id, bool load = true );
    UFUNCTION( BlueprintCallable )
    int GetTownId() const noexcept;

    UFUNCTION( BlueprintCallable )
    FString GetTownName() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool OwnByPlayer() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool OwnByKingdom() const noexcept;

    UFUNCTION( BlueprintCallable )
    int GetKingdomId() const noexcept;

    void SetOwnerKingdom( int kingdomId );

    void SetMoney( int money );
    UFUNCTION( BlueprintCallable )
    int GetMoney() const noexcept;

    void SetFood( int food );
    UFUNCTION( BlueprintCallable )
    int GetFood() const noexcept;

    void SetSoldierNumber( int num );
    UFUNCTION( BlueprintCallable )
    int GetSoldierNumber() const noexcept;

protected:
    static UDataTable* g_lib;

    int m_n_town_id;
    FString m_s_town_name;
    int m_n_own_by_kingdom;
    int m_n_money;
    int m_n_food;
    int m_n_soldier_num;
};
