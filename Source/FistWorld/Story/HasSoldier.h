// Copyright 2019

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FISTWORLD_API HasSoldier
{
public:
	HasSoldier();
	virtual ~HasSoldier();

    void SetSoldierNumber( int num );
    virtual int GetSoldierNumber() const noexcept;
    void IncreaseSoldierNumber( int volume );

protected:
    int m_n_soldier_num;
};
