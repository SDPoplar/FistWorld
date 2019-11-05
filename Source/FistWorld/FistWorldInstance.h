// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
//  #include "FistWorldSave.h"
#include "Story/Kingdom.h"
//  #include "Engine/DataTable.h"
#include "FistWorldInstance.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFistWorldInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    UFistWorldInstance();
    static UFistWorldInstance* GetInstance( const UObject* getter );

    UKingdom* GetMyKingdom() const;
    bool HasGame() const;
    bool HasGameLoaded() const;

    bool LoadGame();

    UFUNCTION( BlueprintCallable )
    bool IsPlayerKingdom( int kingdomId ) const noexcept;

    UFUNCTION( BlueprintCallable )
    UKingdom* FindKingdom( int kingdomId );

    UFUNCTION( BlueprintCallable )
    class UTown* FindTown( int townId );

    UFUNCTION( BlueprintCallable )
    class UWarrior* FindWarrior( int warriorId );

protected:
    TArray<UKingdom*> m_kingdoms;
    UKingdom* m_player_kingdom;

    TArray<class UTown*> m_towns;
    TArray<class UWarrior*> m_warriors;

    bool m_b_game_exists;

    //  static UDataTable* g_chapters;
};
