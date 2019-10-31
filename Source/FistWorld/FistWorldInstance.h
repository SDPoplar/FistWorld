// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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

    bool CreateGame( int nChapterId );
    bool LoadGame();

protected:
    TArray<UKingdom*> m_kingdoms;
    UKingdom* m_player_kingdom;

    bool m_b_game_exists;
    bool m_b_game_loaded;

    //  static UDataTable* g_chapters;
};
