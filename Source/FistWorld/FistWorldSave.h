// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Story/Warrior.h"
#include "Engine/DataTable.h"
#include "Level/Fight.h"
#include "FistWorldSave.generated.h"

USTRUCT( BlueprintType )
struct FChapterDefaultTown : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
public:
    UPROPERTY( BlueprintReadOnly )
    int line;

    UPROPERTY( BlueprintReadOnly )
    int chapter;

    UPROPERTY( BlueprintReadOnly )
    int id;

    UPROPERTY( BlueprintReadOnly )
    int kingdom;

    UPROPERTY( BlueprintReadOnly )
    int money;

    UPROPERTY( BlueprintReadOnly )
    int food;

    UPROPERTY( BlueprintReadOnly )
    int business;

    UPROPERTY( BlueprintReadOnly )
    int agriculture;
};

USTRUCT()
struct FSaveTown
{
    GENERATED_USTRUCT_BODY()

public:
    FSaveTown();
    FSaveTown( const FChapterDefaultTown& def );
    FSaveTown( const class UTown& ins );

    UPROPERTY()
    int TownId;

    UPROPERTY()
    int KingdomId;

    UPROPERTY()
    int Money;

    UPROPERTY()
    int Food;

    UPROPERTY()
    int Soldiers;

    UPROPERTY()
    int Business;

    UPROPERTY()
    int Agriculture;

    //FSaveTown& operator = ( const FChapterDefaultTown& def );
};

USTRUCT( BlueprintType )
struct FChapterDefaultWarrior : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY( BlueprintReadOnly )
    int line;

    UPROPERTY( BlueprintReadOnly )
    int chapter;

    UPROPERTY( BlueprintReadOnly )
    int id;

    UPROPERTY( BlueprintReadOnly )
    int kingdom;

    UPROPERTY( BlueprintReadOnly )
    int town;

    UPROPERTY( BlueprintReadOnly )
    int level;

    UPROPERTY( BlueprintReadOnly )
    int soldiers;
};

USTRUCT()
struct FSaveWarrior
{
    GENERATED_USTRUCT_BODY()

public:
    FSaveWarrior();
    FSaveWarrior( const FChapterDefaultWarrior& def );
    FSaveWarrior( const UWarrior& ins );

    UPROPERTY()
    int WarriorId;

    UPROPERTY()
    int KingdomId;

    UPROPERTY()
    int InTown;

    UPROPERTY()
    EWarriorStatus Status;

    UPROPERTY()
    int Level;

    UPROPERTY()
    int Exp;

    UPROPERTY()
    int Soldiers;
};

USTRUCT( BlueprintType )
struct FChapterDefaultKingdom : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY( BlueprintReadOnly )
    int line;

    UPROPERTY( BlueprintReadOnly )
    int chapter;

    UPROPERTY( BlueprintReadOnly )
    int id;

    UPROPERTY( BlueprintReadOnly )
    int food;

    UPROPERTY( BlueprintReadOnly )
    int money;
};

USTRUCT()
struct FSaveKingdom
{
    GENERATED_USTRUCT_BODY()

public:
    FSaveKingdom();
    //FSaveKingdom( const FSaveKingdom& obj );
    FSaveKingdom( const FChapterDefaultKingdom& def );
    FSaveKingdom( const class UKingdom& ins );

    UPROPERTY()
    int KingdomId;

    UPROPERTY()
    bool IsPlayerKingdom;

    UPROPERTY()
    int Food;

    UPROPERTY()
    int Money;
};

USTRUCT()
struct FSaveFight
{
    GENERATED_USTRUCT_BODY()

public:
    FSaveFight( const class UFight& Fight );

    UPROPERTY()
        int FromTownId;

    UPROPERTY()
        int TargetTownId;

    UPROPERTY()
        int AttackerKingdomId;

    UPROPERTY()
        TArray<int> AttackerWarriors;
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFistWorldSave : public USaveGame
{
	GENERATED_BODY()
public:
    UFUNCTION( BlueprintCallable )
    static bool FileExists();
    static UFistWorldSave* LoadSave();
    static bool CreateNewSave( int chapter, int kingdom );
    static UFistWorldSave* CreateEmptySaveInstance();

    bool SaveToSlot( int playerIndex = 0 );

    const static FString SaveSlotName;
	
    UPROPERTY( SaveGame )
    int chapter;

    UPROPERTY( SaveGame )
    int round;

    UPROPERTY( SaveGame )
    TArray<FSaveKingdom> kingdoms;
    UPROPERTY( SaveGame )
    TArray<FSaveTown> towns;
    UPROPERTY( SaveGame )
    TArray<FSaveWarrior> warriors;
    UPROPERTY( SaveGame )
    TArray<FSaveFight> fights;
};
