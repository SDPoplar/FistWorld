// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "RandomStream.h"

/**
 * 
 */
class FISTWORLD_API RandomMaker
{
public:
	~RandomMaker();

    static RandomMaker* GetInstance();
    static int IntRange( int min, int max );

protected:
    RandomMaker();
    int _intRange( int min, int max );

    static RandomMaker* g_ins;

    FRandomStream m_struct_stream;
};
