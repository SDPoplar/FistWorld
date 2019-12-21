// Fill out your copyright notice in the Description page of Project Settings.

#include "CreateGameWidget.h"
#include "ComboBoxString.h"
#include "FistWorldSave.h"
#include "FistWorldInstance.h"
#include "Widget/MainMenu.h"

bool UCreateGameWidget::RefreshChapter()
{
    auto list = this->GetChapterList();
    if( !list )
    {
        return false;
    }
    list->ClearListItems();
    for( auto ins : UChapterIns::GetAllChapterIns( this ) )
    {
        UE_LOG( LogTemp, Display, TEXT( "Chapter %s found" ), *(ins->GetChapterName()) );
        list->AddItem( ins );
    }
    return true;
}

bool UCreateGameWidget::CreateGame()
{
    auto list = this->GetChapterList();
    auto chap = list ? list->GetSelectedChapterId() : 0;
    if( chap == 0 )
    {
        return false;
    }
    if( !UFistWorldSave::CreateNewSave( chap, 1 ) || !UFistWorldInstance::GetInstance( this )->LoadGame() )
    {
        return false;
    }
    //  todo: enter level( WorldMap );
    if( this->m_parent )
    {
        this->m_parent->StartExistsGame();
    }
    return true;
}

bool UCreateGameWidget::CanClickCreate()
{
    auto list = this->GetChapterList();
    return list && (list->GetNumItemsSelected() > 0);
}

void UCreateGameWidget::BindParent( UMainMenu* parent )
{
    this->m_parent = parent;
}
