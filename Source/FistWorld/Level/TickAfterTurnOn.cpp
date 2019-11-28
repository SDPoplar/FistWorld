// Copyright 2019


#include "TickAfterTurnOn.h"

TickAfterTurnOn::TickAfterTurnOn()
{
}

TickAfterTurnOn::~TickAfterTurnOn()
{
}

void TickAfterTurnOn::TurnOn() noexcept
{
    this->m_b_switch = true;
}

void TickAfterTurnOn::TurnOff() noexcept
{
    this->m_b_switch = false;
}

bool TickAfterTurnOn::IsTickTurnedOff() const noexcept
{
    return !this->m_b_switch;
}
