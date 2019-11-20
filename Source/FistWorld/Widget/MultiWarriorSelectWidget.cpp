// Copyright 2019

#include "MultiWarriorSelectWidget.h"
#include "ListView.h"
#include "Story/Warrior.h"
#include "Controllers/CommonMapController.h"
#include "Kismet/GameplayStatics.h"
#include "Tasks/MultiWarriorTownTask.h"
#include "FistWorldInstance.h"

bool UMultiWarriorSelectWidget::WarriorSelected()
{
    if( !this->m_list_view )
    {
        return false;
    }
    TArray<UObject*> all;
    if( !this->m_list_view->GetSelectedItems( all ) )
    {
        return false;
    }
    auto pc = Cast<ACommonMapController>( UGameplayStatics::GetPlayerController( this, 0 ) );
    if( !pc || !pc->HasTask() || ( pc->GetTask()->GetStep() != ETaskStep::CHOOSING_TARGET_WARRIOR ) )
    {
        return false;
    }
    auto task = Cast<UMultiWarriorTownTask>( pc->GetTask() );
    auto gi = task ? UFistWorldInstance::GetInstance( this ) : nullptr;
    if( !gi )
    {
        return false;
    }
    for( auto item : all )
    {
        UWarriorIns* ins = Cast<UWarriorIns>( item );
        if( ins )
        {
            task->AppendWarrior( gi->FindWarrior( ins->GetWarriorId() ) );
        }
    }
    bool result = task->WarriorSetted();
    if( result )
    {
        this->Quit();
    }
    return result;
}
