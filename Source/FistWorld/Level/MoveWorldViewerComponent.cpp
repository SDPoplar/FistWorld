// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveWorldViewerComponent.h"

void UMoveWorldViewerComponent::StartMove( FVector target, int steps )
{
    FVector stepvolume = ( target - this->GetActorLocation() ) / steps;
    TArray<FVector> task;
    for( int i=0; i<steps; i++ )
    {
        task.Push( stepvolume );
    }
    this->m_movement_tasks.Push( task );
}

void UMoveWorldViewerComponent::MoveTick()
{
    for( auto item : this->m_movement_tasks )
    {
        if( item.Num() <= 0 )
        {
            this->m_movement_tasks.Remove( item );
            continue;
        }
        this->AddInputVector( item.Pop() );
    }
}
