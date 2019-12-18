// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Slate/CommonWidgetText.h"
#include "FightStaticText.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFightRunAwayText : public UCommonAliFontText
{
	GENERATED_BODY()

public:
    UFightRunAwayText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};
