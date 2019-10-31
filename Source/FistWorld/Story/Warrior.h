// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Warrior.generated.h"

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
};
