// Fill out your copyright notice in the Description page of Project Settings.

#include "Town.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"
#include "RandomMaker.h"

UDataTable* UTown::g_lib = nullptr;

UTown::UTown() : HasMoneyAndFood(), HasSoldier(), m_n_town_id( 0 ), m_s_town_name( "" ), m_n_own_by_kingdom( 0 )
{
    if( !UTown::g_lib )
    {
        UTown::g_lib = LoadObject<UDataTable>( nullptr, TEXT( "DataTable'/Game/Datatables/Data_TownBase.Data_TownBase'" ) );
    }
    this->m_o_agriculture.BindSaver( &this->m_n_food );
    this->m_o_business.BindSaver( &this->m_n_money );
}

UTown::~UTown()
{}

int UTown::GetTownId() const noexcept
{
    return this->m_n_town_id;
}

bool UTown::SetTownId( int id, bool load )
{
    this->m_n_town_id = id;
    if( !load )
    {
        return true;
    }
    if( ( id == 0 ) || !UTown::g_lib )
    {
        return false;
    }
    char lineIndex[ 8 ];
    sprintf_s( lineIndex, 8, "%d", this->m_n_town_id );
    FTownBaseData* data = UTown::g_lib->FindRow<FTownBaseData>( lineIndex, "id" );
    if( !data )
    {
        return false;
    }
    this->m_s_town_name = data->name;
    this->m_o_business.SetMax( data->max_business );
    this->m_o_agriculture.SetMax( data->max_agriculture );
    return true;
}

FString UTown::GetTownName() const noexcept
{
    return this->m_s_town_name;
}

bool UTown::OwnByPlayer( void ) const noexcept
{
    return UKingdom::OwnByPlayer( this->m_n_own_by_kingdom );
}

void UTown::SetOwnerKingdom( int kingdomId )
{
    this->m_n_own_by_kingdom = kingdomId;
}

bool UTown::OwnByKingdom() const noexcept
{
    return !!this->m_n_own_by_kingdom;
}

int UTown::GetKingdomId() const noexcept
{
    return this->m_n_own_by_kingdom;
}

int UTown::GetCurrentAgricultureDevelopment( void ) const noexcept
{
    return this->m_o_agriculture.GetCurrent();
}

int UTown::GetCurrentBusinessDevelopment( void ) const noexcept
{
    return this->m_o_business.GetCurrent();
}

int UTown::AppendArrive( UTown* town )
{
    this->m_arr_can_arrive.AddUnique( town );
    return this->m_arr_can_arrive.Num();
}

EArriveStatus UTown::GetArriveStatus( UTown* town, const TownArriveMode mode ) const noexcept
{
    if( town == this )
    {
        return EArriveStatus::Self;
    }
    if( !mode.IsFriendlyMode() && ( this->GetKingdomId() == town->GetKingdomId() ) )
    {
        return EArriveStatus::Friendly;
    }
    if( !mode.IsAttackMode() && ( this->GetKingdomId() != town->GetKingdomId() ) )
    {
        return EArriveStatus::Hostile;
    }
    if( mode.IsDirectMode() && ( this->m_arr_can_arrive.Find( town ) != INDEX_NONE ) )
    {
        return EArriveStatus::CanArrive;
    }
    if( !mode.IsDirectMode() && mode.IsAttackMode() && this->HaveAttackPath( town ) )
    {
        return EArriveStatus::CanArrive;
    }
    TArray<const UTown*> history;
    if( !mode.IsDirectMode() && mode.IsFriendlyMode() && this->FindFriendlyPath( town, history ) )
    {
        return EArriveStatus::CanArrive;
    }
    return EArriveStatus::NoPathFound;
}

EElemGrade UTown::GetGrade() const noexcept
{
    int totaldev = this->m_o_agriculture.GetMax() + this->m_o_business.GetMax();
    if( totaldev > 15000 )
    {
        return EElemGrade::LEGEND;
    }
    if( totaldev > 12000 )
    {
        return EElemGrade::RARE;
    }
    if( totaldev > 9000 )
    {
        return EElemGrade::GOOD;
    }
    return EElemGrade::NORMAL;
}

UTown* UTown::GetFirstRunAwayTarget( void ) const noexcept
{
    for( auto town : this->m_arr_can_arrive )
    {
        if( town->GetKingdomId() == this->GetKingdomId() )
        {
            return town;
        }
    }
    return nullptr;
}

TArray<UTown*> UTown::GetHostileNeighbours( int kingdomLimit ) const noexcept
{
    TArray<UTown*> ret;
    for( auto t : this->m_arr_can_arrive )
    {
        if( this->GetKingdomId() == t->GetKingdomId() )
        {
            continue;
        }
        if( kingdomLimit && (kingdomLimit != t->GetKingdomId()) )
        {
            continue;
        }
        ret.Push( t );
    }
    return ret;
}

TArray<UTown*> UTown::GetFriendlyNeighbour() const noexcept
{
    TArray<UTown*> ret;
    for( auto t : this->m_arr_can_arrive )
    {
        if( t->GetKingdomId() == this->GetKingdomId() )
        {
            ret.Push( t );
        }
    }
    return ret;
}

bool UTown::FindFriendlyPath( const UTown* target, TArray<const UTown*> path ) const noexcept
{
    path.Push( this );
    for( auto t : this->GetFriendlyNeighbour() )
    {
        if( ( t == target ) || ( path.Find( t ) == INDEX_NONE ) && t->FindFriendlyPath( target, path ) )
        {
            return true;
        }
    }
    return false;
}

bool UTown::HaveAttackPath( const UTown* target ) const noexcept
{
    for( auto t : target->GetHostileNeighbours( this->GetKingdomId() ) )
    {
        TArray<const UTown*> history;
        if( this->FindFriendlyPath( t, history ) )
        {
            return true;
        }
    }
    return false;
}

int UTownIns::GetTownId() const noexcept
{
    return UTown::GetTownId();
}

FString UTownIns::GetTownName() const noexcept
{
    return UTown::GetTownName();
}

bool UTownIns::OwnByPlayer() const noexcept
{
    return UTown::OwnByPlayer();
}

bool UTownIns::OwnByKingdom() const noexcept
{
    return UTown::OwnByKingdom();
}

int UTownIns::GetKingdomId() const noexcept
{
    return UTown::GetKingdomId();
}

int UTownIns::GetMoney() const noexcept
{
    return UTown::GetMoney();
}

int UTownIns::GetFood() const noexcept
{
    return UTown::GetFood();
}

int UTownIns::GetSoldierNumber() const noexcept
{
    return UTown::GetSoldierNumber();
}

UTownIns& UTownIns::operator=( const UTown* town )
{
    this->m_n_town_id = town->GetTownId();
    this->m_s_town_name = town->GetTownName();
    this->m_n_own_by_kingdom = town->GetKingdomId();
    this->m_n_money = town->GetMoney();
    this->m_n_food = town->GetFood();
    this->m_n_soldier_num = town->GetSoldierNumber();
    return *this;
}

DevelopableProperty& UTown::GetBusinessDevelopment()
{
    return this->m_o_business;
}

DevelopableProperty& UTown::GetAgricultureDevelopment()
{
    return this->m_o_agriculture;
}

//  =====================   DevelopmentProperty =========================================
DevelopableProperty::DevelopableProperty() : m_n_max( 0 ), m_n_current( 0 ), m_p_saver( nullptr )
{}

DevelopableProperty& DevelopableProperty::operator =( const FIntPoint& obj )
{
    this->m_n_max = obj.X;
    this->m_n_current = obj.Y;
    return *this;
}

void DevelopableProperty::BindSaver( int* saver )
{
    this->m_p_saver = saver;
}

FIntPoint DevelopableProperty::GetPoint()
{
    FIntPoint ret( this->m_n_max, this->m_n_current );
    return ret;
}

void DevelopableProperty::SetMax( int max )
{
    this->m_n_max = max;
}

void DevelopableProperty::SetCurrent( int current )
{
    this->m_n_current = current;
    if( (m_n_max > 0) && ( this->m_n_max < this->m_n_current ) )
    {
        this->m_n_current = this->m_n_max;
    }
}

void DevelopableProperty::IncreaseCurrent( int volume )
{
    int range = volume / 3;
    this->SetCurrent( this->m_n_current + RandomMaker::IntRange( volume - range, volume + range ) );
}

FString DevelopableProperty::ToString() const
{
    char buff[ 128 ];
    sprintf_s( buff, 128, "%d/%d", this->m_n_current, this->m_n_max );
    return FString( buff );
}

int DevelopableProperty::GetMax( void ) const noexcept
{
    return this->m_n_max;
}

int DevelopableProperty::GetCurrent( void ) const noexcept
{
    return this->m_n_current;
}

float DevelopableProperty::GetPercent( void ) const noexcept
{
    return 1.0f * this->GetCurrent() / this->GetMax();
}

bool DevelopableProperty::IsFull() const noexcept
{
    return this->GetCurrent() >= this->GetMax();
}

void DevelopableProperty::Ballance()
{
    if( this->m_p_saver )
    {
        *(this->m_p_saver) += (this->GetCurrent() / 10);
    }
}

//  TownArriveMode

TownArriveMode TownArriveMode::Direct = TownArriveMode( true, true, true );
TownArriveMode TownArriveMode::DirectFriendly = TownArriveMode( true, false, true );
TownArriveMode TownArriveMode::DirectAttack = TownArriveMode( true, true, false );
TownArriveMode TownArriveMode::RecursionFriendly = TownArriveMode( false, false, true );
TownArriveMode TownArriveMode::RecursionAttack = TownArriveMode( false, true, false );

