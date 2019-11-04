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
    UFUNCTION( BlueprintCallable )
    int GetKingdomId() const;

    UFUNCTION( BlueprintCallable )
    bool IsPlayerKingdom() const;

    UFUNCTION( BlueprintCallable )
    void SetPlayerKingdom( const bool isPlayerKingdom = true );

    UFUNCTION( BlueprintCallable )
    FString GetKingdomName() const;

    int AppendWarrior( class UWarrior* warrior );

    UFUNCTION( BlueprintCallable )
    UTexture2D* GetLogo();

protected:
    int m_n_kingdom_id;
    FString m_s_name;
    bool m_b_own_by_player;
    UTexture2D* m_texture_logo;

    TArray<class UWarrior*> m_has_warriors;

    static UDataTable* g_lib;
    static std::map<int, UTexture2D*> logolib;
    static UTexture2D* defKingdomLogo;
};
