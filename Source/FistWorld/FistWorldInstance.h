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

    UKingdom* FindKingdom( int kingdomId );
    UFUNCTION( BlueprintCallable )
    UKingdomIns* FindKingdomInstance( int kingdomId );

    class UTown* FindTown( int townId );
    UFUNCTION( BlueprintCallable )
    class UTownIns* FindTownInstance( int townId );

    class UWarrior* FindWarrior( int warriorId );
    UFUNCTION( BlueprintCallable )
    class UWarriorIns* FindWarriorInstance( int warriorId );

    UFUNCTION( BlueprintCallable )
    int GetCurrentChapter() const noexcept;

    UFUNCTION( BlueprintCallable )
    int GetCurrentRound() const noexcept;

    int CountPlayerTown() const noexcept;
    int CountPlayerWarrior() const noexcept;

    TArray<class UWarrior*>& GetWarriorList();
    TArray<class UTown*>& GetTownList();
    TArray<class UKingdom*>& GetKingdomList();

protected:
    TArray<UKingdom*> m_kingdoms;
    UKingdom* m_player_kingdom;

    TArray<class UTown*> m_towns;
    TArray<class UWarrior*> m_warriors;

    bool m_b_game_exists;

    int m_n_chapter;
    int m_n_round;

    //  static UDataTable* g_chapters;
};
