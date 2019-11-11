// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "FistWorldSave.h"
#include <map>
#include "Kingdom.generated.h"

class UTexture2D;

USTRUCT( BlueprintType )
struct FKingdomBaseData : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:

    UPROPERTY( BlueprintReadOnly )
    int id;

    UPROPERTY( BlueprintReadOnly )
    FString name;
};

class UKingdom
{
public:
    UKingdom();
    virtual ~UKingdom();

    bool SetKingdomId( int id, bool loadData = true );
    virtual int GetKingdomId() const;
    virtual bool IsPlayerKingdom() const;
    virtual void SetPlayerKingdom( const bool isPlayerKingdom = true );
    virtual FString GetKingdomName() const;
    virtual UTexture2D* GetLogo() const;
    static UTexture2D* GetDefaultLogo();

protected:
    static void LoadResource();

    int m_n_kingdom_id;
    FString m_s_name;
    bool m_b_own_by_player;
    UTexture2D* m_texture_logo;

private:
    static UDataTable* g_lib;
    static std::map<int, UTexture2D*> logolib;
    static UTexture2D* defKingdomLogo;
};
/**
 * 
 */
UCLASS()
class FISTWORLD_API UKingdomIns : public UObject, public UKingdom
{
	GENERATED_BODY()
	
public:
    UKingdomIns() : UObject(), UKingdom() {}

    UFUNCTION( BlueprintCallable )
    int GetKingdomId() const override;

    UFUNCTION( BlueprintCallable )
    bool IsPlayerKingdom() const override;

    UFUNCTION( BlueprintCallable )
    void SetPlayerKingdom( const bool isPlayerKingdom = true ) override;

    UFUNCTION( BlueprintCallable )
    FString GetKingdomName() const override;

    UFUNCTION( BlueprintCallable )
    UTexture2D* GetLogo() const override;

    UKingdomIns& operator = ( const UKingdom* obj );
};
