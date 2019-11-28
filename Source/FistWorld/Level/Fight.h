// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fight.generated.h"

class UFight
{
public:
    UFight( class UKingdom* attackerKingdom = nullptr, class UTown* fromTown = nullptr, class UTown* toTown = nullptr );
    bool IsValid() const noexcept;
    int AppendAttackerWarrior( class UWarrior* warrior );
    TArray<class UWarrior*>& GetAttackerWarriors();
    bool IsPlayerAttack() const noexcept;
    class UKingdom* GetAttackerKingdom() const noexcept;
    class UTown* GetFromTown() const noexcept;
    class UTown* GetTargetTown() const noexcept;

protected:
    class UKingdom* m_o_attacker_kingdom;
    class UTown *m_o_from_town, *m_o_to_town;
    TArray<class UWarrior*> m_attacker_warriors;
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFightIns : public UObject, public UFight
{
	GENERATED_BODY()
public:
    UFightIns( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() ) : UObject( ObjectInitializer ),
        UFight(), m_o_reporter( nullptr ) {}

    UFightIns& operator = ( UFight* fight );

    void SetDefencer( TArray<class UWarrior*> warriors );
    void BindReporter( class AFightReporter* reporter );

    TArray<class UWarrior*>& GetDefencerWarriors();

protected:
    class AFightReporter* m_o_reporter;
    TArray<class UWarrior*> m_defencer_warriors;
};
