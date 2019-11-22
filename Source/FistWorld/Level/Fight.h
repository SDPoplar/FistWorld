// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fight.generated.h"

class UFight
{
public:
    UFight( class UKingdom* attackerKingdom, class UTown* fromTown, class UTown* toTown );
    bool IsValid() const noexcept;
    int AppendAttackerWarrior( class UWarrior* warrior );
    TArray<class UWarrior*>& GetAttackerWarriors();

protected:
    class UKingdom* m_o_attacker_kingdom;
    class UTown *m_o_from_town, *m_o_to_town;
    TArray<class UWarrior*> m_attacker_warriors;
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFightIns : public UObject
{
	GENERATED_BODY()
public:
    UFightIns( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() ) : UObject( ObjectInitializer ) {}
};
