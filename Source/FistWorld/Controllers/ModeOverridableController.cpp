// Fill out your copyright notice in the Description page of Project Settings.


#include "ModeOverridableController.h"

AModeOverridableController::AModeOverridableController( const FObjectInitializer& ObjectInitializer )
    : AFistWorldController( ObjectInitializer )
{}

void AModeOverridableController::PushInputMode( const FInputModeUIOnly& mode )
{
    this->uohis.Push( mode );
    this->imhistory.Push( EInputMode::UIOnly );
    this->SetInputMode( mode );
}

void AModeOverridableController::PushInputMode( const FInputModeGameOnly& mode )
{
    this->gohis.Push( mode );
    this->imhistory.Push( EInputMode::GameOnly );
    this->SetInputMode( mode );
}

void AModeOverridableController::PushInputMode( const FInputModeGameAndUI& mode )
{
    this->guhis.Push( mode );
    this->imhistory.Push( EInputMode::GameAndUI );
    this->SetInputMode( mode );
}

void AModeOverridableController::PopInputMode( void )
{
    if( !this->imhistory.Num() )
    {
        return;
    }
    switch( this->imhistory.Pop() )
    {
    case EInputMode::GameAndUI:
        this->guhis.Pop();
        break;
    case EInputMode::GameOnly:
        this->gohis.Pop();
        break;
    case EInputMode::UIOnly:
        this->uohis.Pop();
    }
    if( !this->imhistory.Num() )
    {
        return;
    }
    FInputModeGameAndUI gumode;
    FInputModeGameOnly gomode;
    FInputModeUIOnly uomode;
    switch( this->imhistory[ 0 ] )
    {
    case EInputMode::GameAndUI:
        gumode = this->guhis[ 0 ];
        this->SetInputMode( gumode );
        break;
    case EInputMode::GameOnly:
        gomode = this->gohis[ 0 ];
        this->SetInputMode( gomode );
        break;
    case EInputMode::UIOnly:
        uomode = this->uohis[ 0 ];
        this->SetInputMode( uomode );
    }
}
