// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FistWorldSave.generated.h"

USTRUCT()
struct FSaveKingdomTown
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY()
    int TownId;
};

USTRUCT()
struct FSaveKingdomWarrior
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY()
    int WarriaId;

    UPROPERTY()
    int InTown;
};

USTRUCT()
struct FSaveKingdom
{
    GENERATED_USTRUCT_BODY()

public:

    UPROPERTY()
    int KingdomId;

    UPROPERTY()
    bool IsPlayerKingdom;

    UPROPERTY()
    TArray<FSaveKingdomTown> Towns;

    UPROPERTY()
    TArray<FSaveKingdomWarrior> Warriors;
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
};
