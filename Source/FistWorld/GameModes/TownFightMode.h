// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TownFightMode.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API ATownFightMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    ATownFightMode();
    //  virtual ~ATownFightMode();

    static ATownFightMode* Get( UObject* getter );

    //  void NextRound();
    void LoadFirstFight();
    void FightFinish( bool attackerWin, TArray<FText> attackerResult, TArray<FText> defencerResult );

    void AttackerWin();
    void DefencerWin();

    bool StartFight();

protected:
    TArray<class UWarrior*> AiChooseDefencer( class UTown* town, int max );

    class UFightIns* m_o_current_fight;
};
