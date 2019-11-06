// Fill out your copyright notice in the Description page of Project Settings.

#include "FistWorldSave.h"
#include "Kismet/GameplayStatics.h"
#include "FistWorldInstance.h"

//  ===================== save struct constructs ============================================

FSaveTown::FSaveTown() : TownId( 0 ), KingdomId( 0 ), Money( 0 ), Food( 0 )
{}

FSaveTown::FSaveTown( const FChapterDefaultTown& def )
{
    this->TownId = def.id;
    this->KingdomId = def.kingdom;
    this->Money = def.money;
    this->Food = def.food;
    this->Soldiers = 0;
}

FSaveKingdom::FSaveKingdom() : KingdomId( 0 ), IsPlayerKingdom( false )
{}

FSaveKingdom::FSaveKingdom( const FChapterDefaultKingdom& def )
{
    this->KingdomId = def.id;
    this->IsPlayerKingdom = false;
}

FSaveWarrior::FSaveWarrior() : WarriorId( 0 ), KingdomId( 0 ), InTown( 0 ), Status( EWarriorStatus::NORMAL ),
    Level( 0 ), Exp( 0 ), Soldiers( 0 )
{}

FSaveWarrior::FSaveWarrior( const FChapterDefaultWarrior& def )
{
    this->WarriorId = def.id;
    this->KingdomId = def.kingdom;
    this->InTown = def.town;
    this->Status = EWarriorStatus::NORMAL;
    this->Level = def.level;
    this->Exp = 0;
    this->Soldiers = 0;
}

//  ===================== UFistWorldSave ====================================================

const FString UFistWorldSave::SaveSlotName = TEXT( "fistworld" );

bool UFistWorldSave::FileExists( void )
{
    return UGameplayStatics::DoesSaveGameExist( UFistWorldSave::SaveSlotName, 0 );
}

UFistWorldSave* UFistWorldSave::LoadSave()
{
    return UFistWorldSave::FileExists()
        ? Cast<UFistWorldSave>( UGameplayStatics::LoadGameFromSlot( UFistWorldSave::SaveSlotName, 0 ) )
        : nullptr;
}

bool UFistWorldSave::CreateNewSave( int chapter, int kingdomId )
{
    UDataTable* town = LoadObject<UDataTable>( nullptr,
        TEXT( "DataTable'/Game/Datatables/Data_ChapterDefalutTown.Data_ChapterDefalutTown'" ) );
    UDataTable* warrior = town ? LoadObject<UDataTable>( nullptr,
        TEXT( "DataTable'/Game/Datatables/Data_ChapterDefaultWarrior.Data_ChapterDefaultWarrior'" ) ) : nullptr;
    UDataTable* kingdom = town && warrior ? LoadObject<UDataTable>( nullptr,
        TEXT( "DataTable'/Game/Datatables/Data_ChapterDefaultKingdom.Data_ChapterDefaultKingdom'" ) ) : nullptr;
    if( !kingdom )
    {
        if( !town )
        {
            UE_LOG( LogTemp, Error, TEXT( "Failed to load ChapterDefaultTown" ) );
        }
        if( town && !warrior )
        {
            UE_LOG( LogTemp, Error, TEXT( "Failed to load ChapterDefaultWarrior" ) );
        }
        if( warrior && !kingdom )
        {
            UE_LOG( LogTemp, Error, TEXT( "Failed to load ChapterDefaultKingdom" ) );
        }
        return false;
    }
    char chapterIndex[ 16 ];
    sprintf_s( chapterIndex, 16, "chapter=%d", chapter );
    auto save = Cast<UFistWorldSave>( UGameplayStatics::CreateSaveGameObject( UFistWorldSave::StaticClass() ) );
    //  todo: write default data
    TArray<FChapterDefaultTown*> deftown;
    town->GetAllRows( chapterIndex, deftown );
    for( auto item : deftown )
    {
        save->towns.Push( FSaveTown( *item ) );
    }
    TArray<FChapterDefaultWarrior*> defwarrior;
    warrior->GetAllRows( chapterIndex, defwarrior );
    for( auto item : defwarrior )
    {
        save->warriors.Push( FSaveWarrior( *item ) );
    }
    TArray<FChapterDefaultKingdom*> defkingdom;
    kingdom->GetAllRows( chapterIndex, defkingdom );
    for( auto item : defkingdom )
    {
        FSaveKingdom ins( *item );
        ins.IsPlayerKingdom = (ins.KingdomId == kingdomId);
        save->kingdoms.Push( ins );
    }
    UE_LOG( LogTemp, Error, TEXT( "Default data found: T = %d, W = %d, K = %d" ), deftown.Num(), defwarrior.Num(), defkingdom.Num() );
    return UGameplayStatics::SaveGameToSlot( save, UFistWorldSave::SaveSlotName, 0 );
}
