// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Story/Warrior.h"
#include "FistWorldSave.generated.h"

USTRUCT()
struct FSaveTown
{
    GENERATED_USTRUCT_BODY()

public:
    //UPROPERTY( BlueprintReadOnly )
    int TownId;

    //UPROPERTY( BlueprintReadOnly )
    int KingdomId;

    //UPROPERTY( BlueprintReadOnly )
    int Money;

    //UPROPERTY( BlueprintReadOnly )
    int Food;

    //UPROPERTY( BlueprintReadOnly )
    int Soldiers;
};

USTRUCT()
struct FSaveWarrior
{
    GENERATED_USTRUCT_BODY()

public:
    //UPROPERTY( BlueprintReadOnly )
    int WarriorId;

    //UPROPERTY( BlueprintReadOnly )
    int KingdomId;

    //UPROPERTY( BlueprintReadOnly )
    int InTown;

    //UPROPERTY( BlueprintReadOnly )
    EWarriorStatus Status;

    //UPROPERTY( BlueprintReadOnly )
    int Level;

    //UPROPERTY( BlueprintReadOnly )
    int Exp;

    //UPROPERTY( BlueprintReadOnly )
    int Soldiers;
};

USTRUCT()
struct FSaveKingdom
{
    GENERATED_USTRUCT_BODY()

public:

    //UPROPERTY()
    int KingdomId;

    //UPROPERTY()
    bool IsPlayerKingdom;
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
    static void CreateNewSave( int chapter, int kingdom );

    const static FString SaveSlotName;
	
    UPROPERTY()
    TArray<FSaveKingdom> kingdoms;
    UPROPERTY()
    TArray<FSaveTown> towns;
    UPROPERTY()
    TArray<FSaveWarrior> warriors;
};
