// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMapElement.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

APlayerController* WorldMapElement::GetWorldMapPC()
{
    return UGameplayStatics::GetPlayerController( this->SelfPointer(), 0 );
}
