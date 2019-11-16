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

    UPROPERTY( BlueprintReadOnly )
    int max_business;

    UPROPERTY( BlueprintReadOnly )
    int max_agriculture;
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

protected:
    int m_n_max;
    int m_n_current;

    int* m_p_saver;
};

class UTown
{
public:
    UTown();
    virtual ~UTown();
    bool SetTownId( int id, bool load = true );
    virtual int GetTownId() const noexcept;
    virtual FString GetTownName() const noexcept;
    virtual bool OwnByPlayer( const UObject* getter ) const noexcept;
    virtual bool OwnByKingdom() const noexcept;
    virtual int GetKingdomId() const noexcept;
    void SetOwnerKingdom( int kingdomId );
    void SetMoney( int money );
    virtual void IncreaseMoney( int money );
    virtual int GetMoney() const noexcept;
    void SetFood( int food );
    virtual void IncreaseFood( int food );
    virtual int GetFood() const noexcept;
    void SetSoldierNumber( int num );
    virtual int GetSoldierNumber() const noexcept;

    DevelopableProperty& GetBusinessDevelopment();
    DevelopableProperty& GetAgricultureDevelopment();

protected:
    int m_n_town_id;
    FString m_s_town_name;
    int m_n_own_by_kingdom;
    int m_n_money;
    int m_n_food;
    int m_n_soldier_num;
    DevelopableProperty m_o_business, m_o_agriculture;

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

    UFUNCTION( BlueprintCallable )
    int GetTownId() const noexcept override;

    UFUNCTION( BlueprintCallable )
    FString GetTownName() const noexcept override;

    UFUNCTION( BlueprintCallable )
    bool IsOwnByPlayer() const noexcept;

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
