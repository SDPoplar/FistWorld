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
    auto list = this->GetWarriorListView();
    auto pc = list ? Cast<ACommonMapController>( UGameplayStatics::GetPlayerController( this, 0 ) ) : nullptr;
    if( !pc || !pc->HasTask() || ( pc->GetTask()->GetStep() != ETaskStep::CHOOSING_TARGET_WARRIOR ) )
    {
        return false;
    }
    auto task = Cast<UMultiWarriorTownTask>( pc->GetTask() );
    if( !task )
    {
        return false;
    }
    for( auto item : list->GetSelectedWarriors() )
    {
        task->AppendWarrior( item );
    }
    bool result = task->WarriorSetted();
    if( result )
    {
        this->Quit();
    }
    return result;
}
