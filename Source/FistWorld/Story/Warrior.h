// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Warrior.generated.h"

UENUM( BlueprintType )
enum class EWarriorStatus : uint8
{
    NORMAL,
    WORKING,
    MISSING,
    PRISON,
    DEAD,
};

USTRUCT( BlueprintType )
struct FWarriorBaseData : public FTableRowBase
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
class FISTWORLD_API UWarrior : public UObject
{
	GENERATED_BODY()

public:
    UWarrior();

    bool operator == ( int id );
    bool operator == ( UWarrior* );

    bool SetWarriorId( int id, bool load = true );
    UFUNCTION( BlueprintCallable )
    int GetWarriorId() const noexcept;

    void SetWarriorName( FString name );
    UFUNCTION( BlueprintCallable )
    FString GetWarriorName() const noexcept;

    void SetBelongKingdom( int kingdomId );
    UFUNCTION( BlueprintCallable )
    int GetBelongKingdom() const noexcept;

    void SetInTown( int townId );
    UFUNCTION( BlueprintCallable )
    int GetInTown() const noexcept;

    void SetStatus( EWarriorStatus status );
    UFUNCTION( BlueprintCallable )
    EWarriorStatus GetStatus() const noexcept;

    void SetWarriorLevel( int level );
    UFUNCTION( BlueprintCallable )
    int GetWarriorLevel() const noexcept;

    void SetWarriorExp( int exp );
    UFUNCTION( BlueprintCallable )
    int GetWarriorExp() const noexcept;

    void SetSoldierNumber( int num );
    UFUNCTION( BlueprintCallable )
    int GetSoldierNumber() const noexcept;
	
protected:
    static UDataTable* g_lib;

    int m_n_id;
    FString m_s_name;
    int m_n_kingdom;
    int m_n_in_town;
    EWarriorStatus m_e_status;
    int m_n_level;
    int m_n_exp;
    int m_n_soldier_num;
};
