// Copyright 2019

#include "FighterMovementComponent.h"

UFighterMovementComponent::UFighterMovementComponent( const FObjectInitializer& ObjectInitializer )
    : UFloatingPawnMovement( ObjectInitializer )
{
    this->NavAgentProps.AgentStepHeight = 50.0f;
    this->NavAgentProps.bCanWalk = true;
    this->NavAgentProps.AgentRadius = 50.0f;
    this->NavAgentProps.AgentHeight = 100.0f;
}
