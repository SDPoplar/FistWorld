// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Huds/CommonMapHud.h"
#include "FightMapHud.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AFightMapHud : public ACommonMapHud
{
	GENERATED_BODY()
	
public:
    AFightMapHud( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    class UFightResultWidget* GetFightResultWidget();

protected:
    TSubclassOf<class UFightResultWidget> fightresultClass;

    class UFightResultWidget* m_widget_result;
};
