// Copyright 2019

#include "Chapter.h"

UDataTable* UChapter::g_chapters = nullptr;

UChapter::UChapter() : m_n_chap_id( 0 ), m_s_chap_name( "" )
{}

UDataTable* UChapter::GetChapterData()
{
    if( !UChapter::g_chapters || !UChapter::g_chapters->IsValidLowLevelFast() )
    {
        UChapter::g_chapters = LoadObject<UDataTable>( nullptr,
            TEXT( "DataTable'/Game/Datatables/Data_CreatableChapters.Data_CreatableChapters'" ) );
    }
    if( !UChapter::g_chapters )
    {
        UE_LOG( LogTemp, Error, TEXT( "Load chapter file failed" ) );
    }
    return UChapter::g_chapters;
}

FCreatableChapter* UChapter::FindChapterData() const noexcept
{
    UDataTable* all = UChapter::GetChapterData();
    return all ? all->FindRow<FCreatableChapter>( []( int id )->FName
        {
            char buff[ 8 ] = "";
            sprintf_s( buff, 8, "%d", id );
            return FName( buff );
        }( this->m_n_chap_id ), "id" ) : nullptr;
}

bool UChapter::SetChapterId( int id, bool loadData )
{
    this->m_n_chap_id = id;
    if( !loadData )
    {
        return true;
    }

    auto data = this->FindChapterData();
    if( !data )
    {
        return false;
    }
    this->m_s_chap_name = data->name;
    return true;
}

int UChapter::GetChapterId() const noexcept
{
    return this->m_n_chap_id;
}

FString UChapter::GetChapterName() const noexcept
{
    return this->m_s_chap_name;
}

/*
FString UChapter::GetChapterDescribe() const noexcept
{
    auto data = this->FindChapterData();
    return data ? data->describe : "";
}
*/

UChapterIns::UChapterIns( const FObjectInitializer& ObjectInitializer )
    : UObject( ObjectInitializer ), UChapter(), m_s_describe( FText::GetEmpty() )
{}

FText UChapterIns::GetChapterDescribe() const noexcept
{
    return this->m_s_describe;
}


UChapterIns& UChapterIns::operator=( const FCreatableChapter& data )
{
    this->m_n_chap_id = data.id;
    this->m_s_chap_name = data.name;
    this->m_s_describe = FText::FromString( data.describe );
    return *this;
}

TArray<UChapterIns*> UChapterIns::GetAllChapterIns( UObject* getter )
{
    TArray<UChapterIns*> ret;
    TArray<FCreatableChapter*> rows;
    UChapter::GetChapterData()->GetAllRows<FCreatableChapter>( "", rows );
    for( auto d : rows )
    {
        auto item = NewObject<UChapterIns>( getter );
        *item = *d;
        ret.Push( item );
    }
    if( ret.Num() )
    {
        UE_LOG( LogTemp, Display, TEXT( "%d chapters found" ), ret.Num() );
    }
    else
    {
        UE_LOG( LogTemp, Error, TEXT( "No chapter found" ) );
    }
    return ret;
}
