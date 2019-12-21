// Copyright 2019

#include "ChapterList.h"
#include "Story/Chapter.h"
#include "Widget/ChapterListItemWidget.h"
#include "UObject/ConstructorHelpers.h"

UChapterList::UChapterList( const FObjectInitializer& ObjectInitializer )
    : UListView( ObjectInitializer )
{
    this->SelectionMode = ESelectionMode::Single;
    static ConstructorHelpers::FClassFinder<UChapterListItemWidget> chapitem(
        TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_MainMenu_ChapterItem" ) );
    if( chapitem.Succeeded() )
    {
        this->EntryWidgetClass = chapitem.Class;
    }
}

int UChapterList::GetSelectedChapterId()
{
    UChapterIns* ins = Cast<UChapterIns>( this->GetSelectedItem() );
    return ins ? ins->GetChapterId() : 0;
}
