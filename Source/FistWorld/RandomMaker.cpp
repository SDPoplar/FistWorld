// Copyright 2019

#include "RandomMaker.h"

RandomMaker* RandomMaker::g_ins = nullptr;

RandomMaker::RandomMaker()
{
    RandomMaker::g_ins = this;
    this->m_struct_stream.GenerateNewSeed();
}

RandomMaker::~RandomMaker()
{}

RandomMaker* RandomMaker::GetInstance()
{
    if( !RandomMaker::g_ins )
    {
        new RandomMaker();
    }
    return RandomMaker::g_ins;
}

int RandomMaker::IntRange( int min, int max )
{
    RandomMaker* maker = RandomMaker::GetInstance();
    return maker ? maker->_intRange( min, max ) : ( min + max ) / 2;
}

int RandomMaker::_intRange( int min, int max )
{
    return this->m_struct_stream.RandRange( min, max );
}

bool RandomMaker::WillHappen( int percent )
{
    return RandomMaker::IntRange( 0, 100 ) < percent;
}
