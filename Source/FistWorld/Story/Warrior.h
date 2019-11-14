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

class UWarrior
{
public:
    UWarrior();
    virtual ~UWarrior();

    bool operator == ( int id );
    bool operator == ( UWarrior* );

    bool SetWarriorId( int id, bool load = true );
    virtual int GetWarriorId() const noexcept;
    void SetWarriorName( FString name );
    virtual FString GetWarriorName() const noexcept;
    void SetBelongKingdom( int kingdomId );
    virtual int GetBelongKingdom() const noexcept;
    void SetInTown( int townId );
    virtual int GetInTown() const noexcept;
    void SetStatus( EWarriorStatus status );
    virtual EWarriorStatus GetStatus() const noexcept;
    void SetWarriorLevel( int level );
    virtual int GetWarriorLevel() const noexcept;
    void SetWarriorExp( int exp );
    virtual int GetWarriorExp() const noexcept;
    void SetSoldierNumber( int num );
    virtual int GetSoldierNumber() const noexcept;

protected:
    int m_n_id;
    FString m_s_name;
    int m_n_kingdom;
    int m_n_in_town;
    EWarriorStatus m_e_status;
    int m_n_level;
    int m_n_exp;
    int m_n_soldier_num;

private:
    static UDataTable* g_lib;
};

/**
 * 
 */
UCLASS( BlueprintType )
class FISTWORLD_API UWarriorIns : public UObject, public UWarrior
{
	GENERATED_BODY()

public:
    UWarriorIns() : UObject(), UWarrior() {}

    UFUNCTION( BlueprintCallable )
    int GetWarriorId() const noexcept override;

    UFUNCTION( BlueprintCallable )
    FString GetWarriorName() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetBelongKingdom() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetInTown() const noexcept override;

    UFUNCTION( BlueprintCallable )
    EWarriorStatus GetStatus() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetWarriorLevel() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetWarriorExp() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetSoldierNumber() const noexcept override;

    UWarriorIns& operator=( const UWarrior* obj );
};
