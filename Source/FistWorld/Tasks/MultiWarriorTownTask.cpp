// Copyright 2019

#include "MultiWarriorTownTask.h"
#include "Story/Warrior.h"

int UMultiWarriorTownTask::AppendWarrior( UWarrior* warrior )
{
    this->m_arr_warriors.AddUnique( warrior );
    return this->m_arr_warriors.Num();
}

int UMultiWarriorTownTask::EachWarrior( bool(warriorProc)( class UWarrior*, void* ), void* res )
{
    int valid = 0;
    for( auto item : this->m_arr_warriors )
    {
        if( warriorProc( item, res ) )
        {
            valid++;
        }
    }
    return valid;
}

bool UMultiWarriorTownTask::WarriorSetted()
{
    return this->m_arr_warriors.Num() > 0;
}
