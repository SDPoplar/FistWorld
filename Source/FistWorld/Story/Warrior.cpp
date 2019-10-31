// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"

bool UWarrior::operator==( int id )
{
    return this->m_n_id == id;
}

bool UWarrior::operator==( UWarrior* w )
{
    return *this == w->m_n_id;
}
