// Copyright 2019

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FISTWORLD_API HasMoneyAndFood
{
public:
	HasMoneyAndFood();
	virtual ~HasMoneyAndFood();

    void SetMoney( int money );
    virtual void IncreaseMoney( int money );
    virtual int GetMoney() const noexcept;
    void SetFood( int food );
    virtual void IncreaseFood( int food );
    virtual int GetFood() const noexcept;

protected:
    int m_n_money;
    int m_n_food;
};
