// Fill out your copyright notice in the Description page of Project Settings.


#include "ExcutableTask.h"
//#include "Internationalization/PolyglotTextData.h"
//#include "Internationalization/ILocalizedTextSource.h"
//#include "Internationalization/TextLocalizationManager.h"
//#include "Internationalization/PolyglotTextSource.h"
//#include "Internationalization/TextLocalizationManager.h"

std::map<ETaskStep, FText> UExcutableTask::g_map_step_describe;

UExcutableTask::UExcutableTask( const FObjectInitializer& ObjectInitializer )
    : UObject( ObjectInitializer ), m_e_step( ETaskStep::CREATING ), m_s_last_error( "" )
{
    UExcutableTask::LoadDescribes();
    this->AddToRoot();
}

UExcutableTask::~UExcutableTask()
{}

bool UExcutableTask::Excute()
{
    return true;
}

FString UExcutableTask::GetLastError() const
{
    return this->m_s_last_error;
}

FText UExcutableTask::GetStepDescribe() const
{
    std::map<ETaskStep, FText>::iterator inlib = UExcutableTask::g_map_step_describe.find( this->m_e_step );
    if( inlib != UExcutableTask::g_map_step_describe.end() )
    {
        return inlib->second;
    }
    FString desc = "";
    switch( this->m_e_step )
    {
    case ETaskStep::CREATING:
        desc = "Creating";
        break;
    case ETaskStep::CHOOSING_TARGET_TOWN:
        desc = "Select target town";
        break;
    case ETaskStep::CHOOSING_TARGET_WARRIOR:
        desc = "Select warrior";
        break;
    case ETaskStep::SETTING_TRANSPORT_VOLUME:
        desc = "Set transport volume";
        break;
    case ETaskStep::SETTING_SOLDIER_NUMBER:
        desc = "Set soldier number";
        break;
    case ETaskStep::FINISHED:
        desc = "Finished";
        break;
    case ETaskStep::CANCELED:
        desc = "Canceld";
    }
    return FText::FromString( desc );
}

void UExcutableTask::MarkAsFinished() noexcept
{
    this->m_e_step = ETaskStep::FINISHED;
    this->RemoveFromRoot();
}

void UExcutableTask::MarkAsCanceled() noexcept
{
    this->m_e_step = ETaskStep::CANCELED;
    this->RemoveFromRoot();
}

ETaskStep UExcutableTask::GetStep() const noexcept
{
    return this->m_e_step;
}

bool UExcutableTask::NeedDisplayStep() const noexcept
{
    return false
        || (this->m_e_step == ETaskStep::CHOOSING_TARGET_TOWN)
        || false;
}

bool UExcutableTask::CanCancel( void ) const noexcept
{
    return true
        && (this->m_e_step != ETaskStep::FINISHED)
        && (this->m_e_step != ETaskStep::CANCELED)
        && true;
}

void UExcutableTask::LoadDescribes( void )
{
    /*
    auto& all = FTextLocalizationManager::Get();
    FTextKey ns( "TaskStep" );
    FTextKey keyChoosingTargetTown( "CHOOSING_TARGET_TOWN" );
    auto st = all.FindDisplayString( ns, keyChoosingTargetTown );
    UExcutableTask::g_map_step_describe[ ETaskStep::CHOOSING_TARGET_TOWN ] = FText::FromString( *st );
    //UE_LOG( LogTemp, Display, TEXT( "ST find FText - TaskStep::CHOOSING_TARGET_TOWN = %s" ), *( *st ) );
    */
}
