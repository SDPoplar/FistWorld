// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "HasMoneyAndFood.h"
#include "HasSoldier.h"
#include "GradableElement.h"
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

    UPROPERTY( BlueprintReadOnly )
    int max_business;

    UPROPERTY( BlueprintReadOnly )
    int max_agriculture;
};

UENUM( BlueprintType )
enum class EArriveStatus : uint8
{
    Self,
    CanArrive,
    NoPathFound,
    Friendly,
    Hostile,
    Unoccupied,
};

class TownArriveMode
{
public:

    TownArriveMode( bool direct = false, bool attack = false, bool friendly = false )
        : m_b_direct( direct ), m_b_attack( attack ), m_b_friendly( friendly ) {}

    bool IsDirectMode() const noexcept { return this->m_b_direct; }
    bool IsAttackMode() const noexcept { return this->m_b_attack; }
    bool IsFriendlyMode() const noexcept { return this->m_b_friendly; }

    static TownArriveMode Default() { return TownArriveMode::Direct; }
    static TownArriveMode Direct;
    static TownArriveMode DirectFriendly;
    static TownArriveMode DirectAttack;
    static TownArriveMode RecursionAttack;
    static TownArriveMode RecursionFriendly;

protected:
    bool m_b_direct;
    bool m_b_attack;
    bool m_b_friendly;


};

class DevelopableProperty
{
public:
    DevelopableProperty();
    DevelopableProperty& operator =( const FIntPoint& obj );
    void BindSaver( int* saver );
    FIntPoint GetPoint();
    void SetMax( int max );
    void SetCurrent( int current );
    void IncreaseCurrent( int volume );
    FString ToString() const;
    int GetMax() const noexcept;
    int GetCurrent() const noexcept;
    float GetPercent() const noexcept;
    bool IsFull() const noexcept;
    void Ballance();

protected:
    int m_n_max;
    int m_n_current;

    int* m_p_saver;
};

class UTown : public HasMoneyAndFood, public HasSoldier, public GradableElement
{
public:
    UTown();
    virtual ~UTown();
    bool SetTownId( int id, bool load = true );
    virtual int GetTownId() const noexcept;
    virtual FString GetTownName() const noexcept;
    virtual bool OwnByPlayer( void ) const noexcept;
    virtual bool OwnByKingdom() const noexcept;
    virtual int GetKingdomId() const noexcept;
    void SetOwnerKingdom( int kingdomId );
    int AppendArrive( UTown* town );

    TArray<UTown*> GetFriendlyNeighbour() const noexcept;
    TArray<UTown*> GetHostileNeighbours( int kingdomLimit = 0 ) const noexcept;
    bool FindFriendlyPath( const UTown* target, TArray<const UTown*> path ) const noexcept;
    bool HaveAttackPath( const UTown* target ) const noexcept;

    virtual EArriveStatus GetArriveStatus( UTown* town, const TownArriveMode = TownArriveMode::Default() ) const noexcept;
    virtual EElemGrade GetGrade() const noexcept override;

    DevelopableProperty& GetBusinessDevelopment();
    DevelopableProperty& GetAgricultureDevelopment();
    int GetCurrentBusinessDevelopment() const noexcept;
    int GetCurrentAgricultureDevelopment() const noexcept;

    UTown* GetFirstRunAwayTarget() const noexcept;

protected:
    int m_n_town_id;
    FString m_s_town_name;
    int m_n_own_by_kingdom;
    DevelopableProperty m_o_business, m_o_agriculture;

    TArray<UTown*> m_arr_can_arrive;

private:
    static UDataTable* g_lib;
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownIns : public UObject, public UTown
{
    GENERATED_BODY()

public:
    UTownIns() : UObject(), UTown() {}
    virtual ~UTownIns() {}

    UFUNCTION( BlueprintCallable )
    int GetTownId() const noexcept override;

    UFUNCTION( BlueprintCallable )
    FString GetTownName() const noexcept override;

    UFUNCTION( BlueprintCallable )
    bool OwnByPlayer() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool OwnByKingdom() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetKingdomId() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetMoney() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetFood() const noexcept override;

    UFUNCTION( BlueprintCallable )
    int GetSoldierNumber() const noexcept override;

    UTownIns& operator=( const UTown* town );
};
