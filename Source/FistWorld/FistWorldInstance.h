// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
//  #include "FistWorldSave.h"
#include "Story/Chapter.h"
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

    UKingdom* GetPlayerKingdom() const noexcept;
    UKingdom* FindKingdom( int kingdomId );
    UFUNCTION( BlueprintCallable )
    UKingdomIns* FindKingdomInstance( int kingdomId, UObject* getter );

    class UTown* FindTown( int townId );
    UFUNCTION( BlueprintCallable )
    class UTownIns* FindTownInstance( int townId, UObject* getter );

    class UWarrior* FindWarrior( int warriorId );
    UFUNCTION( BlueprintCallable )
    class UWarriorIns* FindWarriorInstance( int warriorId, UObject* getter );

    UFUNCTION( BlueprintCallable )
    int GetCurrentChapter() const noexcept;

    UFUNCTION( BlueprintCallable )
    FString GetCurrentChapterName() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetCurrentChapterNameText() const noexcept;

    void PlusRound( void );
    UFUNCTION( BlueprintCallable )
    int GetCurrentRound() const noexcept;

    int CountPlayerTown() const noexcept;
    int CountPlayerWarrior() const noexcept;

    int AppendFight( class UFight* fight );
    bool HasFight() const noexcept;
    bool PopFirstAiFight( class UFight*& fight );

    TArray<class UWarrior*>& GetWarriorList();
    TArray<class UTown*>& GetTownList();
    TArray<class UKingdom*>& GetKingdomList();
    TArray<class UFight*>& GetFightList();

protected:
    TArray<UKingdom*> m_kingdoms;
    UKingdom* m_player_kingdom;

    TArray<class UTown*> m_towns;
    TArray<class UWarrior*> m_warriors;

    TArray<class UFight*> m_fights;

    bool m_b_game_exists;

    UChapter m_o_chapter;
    int m_n_round;

    //  static UDataTable* g_chapters;
};
