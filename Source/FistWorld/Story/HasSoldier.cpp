// Copyright 2019


#include "HasSoldier.h"

HasSoldier::HasSoldier() : m_n_soldier_num( 0 )
{}

HasSoldier::~HasSoldier()
{}

void HasSoldier::SetSoldierNumber( int num )
{
    this->m_n_soldier_num = num;
}

int HasSoldier::GetSoldierNumber() const noexcept
{
    return this->m_n_soldier_num;
}

void HasSoldier::IncreaseSoldierNumber( int volume )
{
    this->m_n_soldier_num += volume;
    if( this->m_n_soldier_num < 0 )
    {
        this->m_n_soldier_num = 0;
    }
}
