// Fill out your copyright notice in the Description page of Project Settings.


#include "ExcutableTask.h"

UExcutableTask::UExcutableTask( const FObjectInitializer& ObjectInitializer )
    : UObject( ObjectInitializer ), m_e_step( ETaskStep::CREATING ), m_s_last_error( "" )
{
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

FString UExcutableTask::GetStepDescribe() const
{
    FString desc = "";
    switch( this->m_e_step )
    {
    case ETaskStep::CREATING:
        desc = TCHAR_TO_UTF8( TEXT( "���ڴ���" ) );
        break;
    case ETaskStep::CHOOSING_TARGET_TOWN:
        desc = TCHAR_TO_UTF8( TEXT( "ѡ��Ŀ�����" ) );
        break;
    case ETaskStep::CHOOSING_TARGET_WARRIOR:
        desc = TCHAR_TO_UTF8( TEXT( "ѡ��һ����ʿ" ) );
        break;
    case ETaskStep::SETTING_TRANSPORT_VOLUME:
        desc = TCHAR_TO_UTF8( TEXT( "�������͵���Դ" ) );
        break;
    case ETaskStep::SETTING_SOLDIER_NUMBER:
        desc = TCHAR_TO_UTF8( TEXT( "����ʿ������" ) );
        break;
    case ETaskStep::FINISHED:
        desc = "Finished";
        break;
    case ETaskStep::CANCELED:
        desc = "Canceld";
    }
    return desc;
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
