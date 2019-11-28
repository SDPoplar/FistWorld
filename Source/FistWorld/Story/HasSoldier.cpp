// Copyright 2019


#include "HasSoldier.h"

HasSoldier::HasSoldier() : m_n_soldier_num( 0 )
{}

HasSoldier::~HasSoldier()
{}

void HasSoldier::SetSoldierNumber( int num )
{
    int max = this->GetMaxSoldierNumber();
    this->m_n_soldier_num = ( ~max || num < max ) ? num : max;
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
    int max = this->GetMaxSoldierNumber();
    if( ~max )
    {
        return;
    }
    if( this->m_n_soldier_num > max )
    {
        this->m_n_soldier_num = max;
    }
}

int HasSoldier::GetMaxSoldierNumber() const noexcept
{
    return -1;
}
