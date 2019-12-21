// Copyright 2019

#include "ChapterListItemWidget.h"
#include "Story/Chapter.h"
#include "Slate/ChapterList.h"

UChapterListItemWidget::UChapterListItemWidget( const FObjectInitializer& ObjectInitializer )
    : UUserWidget( ObjectInitializer ), m_o_chap( nullptr )
{}

void UChapterListItemWidget::BindChapter( UObject* item )
{
    auto chap = Cast<UChapterIns>( item );
    if( chap && chap->IsValidLowLevelFast() )
    {
        this->m_o_chap = chap;
    }
}

bool UChapterListItemWidget::IsChapterBinded() const noexcept
{
    return this->m_o_chap && this->m_o_chap->IsValidLowLevel();
}

FText UChapterListItemWidget::GetChapterName() const noexcept
{
    return this->IsChapterBinded() ? FText::FromString( this->m_o_chap->GetChapterName() ) : FText::GetEmpty();
}

FText UChapterListItemWidget::GetChapterDescribe() const noexcept
{
    return this->IsChapterBinded() ? this->m_o_chap->GetChapterDescribe() : FText::GetEmpty();
}

bool UChapterListItemWidget::IsChapterSelected() const noexcept
{
    auto list = this->IsChapterBinded() ? Cast<UChapterList>( this->GetOwningListView() ) : nullptr;
    return list && ( list->GetSelectedChapterId() == this->m_o_chap->GetChapterId() );
}
