// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FISTWORLD_API WorldMapElement
{
public:
    class APlayerController* GetWorldMapPC();

protected:
    virtual UObject* SelfPointer() = 0;
};
