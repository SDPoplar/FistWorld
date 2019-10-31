// Fill out your copyright notice in the Description page of Project Settings.

#include "Kingdom.h"
UDataTable* UKingdom::g_lib = nullptr;

UKingdom::UKingdom() : m_b_own_by_player( false )
{
    if( !g_lib )
    {

    }
}

bool UKingdom::IsPlayerKingdom() const
{
    return this->m_b_own_by_player;
}
