// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Warrior.generated.h"

UENUM( BlueprintType )
enum class EWarriorStatus : uint8
{
    NORMAL,
    WORKING,
    MISSING,
    PRISON,
    DEAD,
};

USTRUCT( BlueprintType )
struct FWarriorBaseData : public FTableRowBase
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
class FISTWORLD_API UWarrior : public UObject
{
	GENERATED_BODY()

public:
    bool operator == ( int id );
    bool operator == ( UWarrior* );
	
protected:
    int m_n_id;
    FString m_s_name;
};
