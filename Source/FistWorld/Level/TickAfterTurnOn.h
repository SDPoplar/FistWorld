// Copyright 2019

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FISTWORLD_API TickAfterTurnOn
{
public:
	TickAfterTurnOn();
	virtual ~TickAfterTurnOn();

    bool IsTickTurnedOff() const noexcept;

    void TurnOn() noexcept;
    void TurnOff() noexcept;

protected:
    bool m_b_switch;
};

#define     DO_WHEN_TURNOFF( act ) do { if( this->IsTickTurnedOff() ) { act } } while( false )

#define     CHECK_TICK_TURNON_NORET DO_WHEN_TURNOFF( return; )
#define     CHECK_TICK_TURNON_RET( ret ) DO_WHEN_TURNOFF( return ret; )
