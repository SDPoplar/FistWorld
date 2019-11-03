// Fill out your copyright notice in the Description page of Project Settings.

#include "CreateGameWidget.h"
#include "ComboBoxString.h"

UDataTable* UCreateGameWidget::chapters = nullptr;

TArray<FCreatableChapter> UCreateGameWidget::GetAllChapters()
{
    TArray<FCreatableChapter> ret;
    if( !UCreateGameWidget::GetChapterTable() )
    {
        return ret;
    }
    for( auto item : UCreateGameWidget::chapters->GetRowNames() )
    {
        FCreatableChapter *cursor = UCreateGameWidget::chapters->FindRow<FCreatableChapter>( item, FString( TEXT( "" ) ) );
        ret.Push( *cursor );
    }
    return ret;
}

UDataTable* UCreateGameWidget::GetChapterTable()
{
    if( !UCreateGameWidget::chapters )
    {
        UCreateGameWidget::chapters = LoadObject<UDataTable>( nullptr,
            TEXT( "DataTable'/Game/Datatables/Data_CreatableChapters.Data_CreatableChapters'" ) );
        if( !UCreateGameWidget::chapters )
        {
            UE_LOG( LogTemp, Error, TEXT( "Failed to load chapter data" ) );
        }
    }
    return UCreateGameWidget::chapters;
}

TArray<FString> UCreateGameWidget::DebugDatatable()
{
    TArray<FString> ret;
    auto table = UCreateGameWidget::GetChapterTable();
    if( !table )
    {
        UE_LOG( LogTemp, Error, TEXT( "Failed to load chapter datatable" ) );
        return ret;
    }
    for( FName name : table->GetRowNames() )
    {
        ret.Push( name.ToString() );
    }
    return ret;
}

UComboBoxString* UCreateGameWidget::RefreshChapter( UComboBoxString* holder )
{
    FString current = ( holder->GetOptionCount() > 0 ) ? holder->GetSelectedOption() : TEXT( "" );
    holder->ClearOptions();
    for( auto item : this->GetAllChapters() )
    {
        holder->AddOption( item.name );
    }
    if( holder->GetOptionCount() == 0 )
    {
        return holder;
    }
    if( ( current != TEXT( "" ) ) && ( holder->FindOptionIndex( current ) >= 0 ) )
    {
        holder->SetSelectedOption( current );
    }
    else
    {
        holder->SetSelectedIndex( 0 );
    }
    return holder;
}
