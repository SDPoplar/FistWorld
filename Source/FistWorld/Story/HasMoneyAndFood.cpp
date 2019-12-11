// Copyright 2019


#include "HasMoneyAndFood.h"

HasMoneyAndFood::HasMoneyAndFood() : m_n_food( 0 ), m_n_money( 0 )
{
}

HasMoneyAndFood::~HasMoneyAndFood()
{
}

void HasMoneyAndFood::SetMoney( int money )
{
    this->m_n_money = money;
}

void HasMoneyAndFood::IncreaseMoney( int money )
{
    this->m_n_money += money;

    // this is a common class, reserve the following lines, even seems no need in one child class
    if( m_n_money < 0 )
    {
        this->m_n_money = 0;
    }
}

int HasMoneyAndFood::GetMoney( void ) const noexcept
{
    return this->m_n_money;
}

void HasMoneyAndFood::SetFood( int food )
{
    this->m_n_food = food;
}

void HasMoneyAndFood::IncreaseFood( int food )
{
    this->m_n_food += food;
    if( this->m_n_food < 0 )
    {
        this->m_n_food = 0;
    }
}

int HasMoneyAndFood::GetFood( void ) const noexcept
{
    return this->m_n_food;
}
