#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "KingdomRoundAi.generated.h"

USTRUCT()
struct FTownStatistics
{
    GENERATED_USTRUCT_BODY();

public:

    class UTown* town;
    TArray<class UWarrior*> warriors;

    FTownStatistics( class UTown* _town = nullptr ) : town( _town ) {}
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UKingdomRoundAi : public UObject
{
	GENERATED_BODY()
	
public:
    UKingdomRoundAi( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    static UKingdomRoundAi* Create( class AWorldMapMode* gm, int chapter, int round );

    UKingdomRoundAi* BindKingdom( class UKingdom* kingdom );
    UKingdomRoundAi* SetTownStatistics( TArray<FTownStatistics> towns );
    bool DoRound();

protected:
    virtual bool Round();
    virtual bool TownRound( FTownStatistics& town ) { return true; }
    virtual void DevTown( FTownStatistics& town );

    /*
        int GiveSoldlier( FTownStatistics& town );
        @return: soldier num still need
    */
    int GiveSoldlier( FTownStatistics& town );
    UKingdomRoundAi* SetCurrentRound( int round );

    bool AgricultureDevTask( class UTown* town, class UWarrior* warrior );
    bool BusinessDevTask( class UTown* town, class UWarrior* warrior );
    bool ConscriptTask( class UTown* town, class UWarrior* warrior );

    int m_n_round;
    class UKingdom* m_o_kingdom;
    TArray<FTownStatistics> m_arr_towns;
};

UCLASS()
class FISTWORLD_API UKingdomRoundAi_Chapter1 : public UKingdomRoundAi
{
    GENERATED_BODY()

public:
    bool TownRound( FTownStatistics& town ) override;
};

UCLASS()
class FISTWORLD_API UKingdomRoundAi_Chapter2 : public UKingdomRoundAi
{
    GENERATED_BODY()

public:
    bool TownRound( FTownStatistics& town ) override;
};

UCLASS()
class FISTWORLD_API UKingdomRoundAi_Chapter3 : public UKingdomRoundAi
{
    GENERATED_BODY()

public:
    bool TownRound( FTownStatistics& town ) override;
};

UCLASS()
class FISTWORLD_API UKingdomRoundAi_Chapter4 : public UKingdomRoundAi
{
    GENERATED_BODY()

public:
    bool TownRound( FTownStatistics& town ) override;
};
