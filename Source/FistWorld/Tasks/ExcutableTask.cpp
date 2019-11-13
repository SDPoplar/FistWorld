// Fill out your copyright notice in the Description page of Project Settings.


#include "ExcutableTask.h"

UExcutableTask::UExcutableTask() : m_e_step( ETaskStep::CREATING ), m_s_last_error( "" )
{}

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
        desc = TEXT( "正在创建" );
        break;
    case ETaskStep::CHOOSING_TARGET_TOWN:
        desc = TEXT( "选择目标城镇" );
        break;
    case ETaskStep::CHOOSING_TARGET_WARRIOR:
        desc = TEXT( "选择一名勇士" );
    }
    return desc;
}

ETaskStep UExcutableTask::GetStep() const noexcept
{
    return this->m_e_step;
}
