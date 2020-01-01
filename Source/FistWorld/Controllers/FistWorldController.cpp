// Copyright 2019

#include "FistWorldController.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AFistWorldController::AFistWorldController( const FObjectInitializer& ObjectInitializer )
    : APlayerController( ObjectInitializer )
{
    static ConstructorHelpers::FClassFinder<UUserWidget> cursor = TEXT( "/Game/Levels/Res_lv_Common/Widget_Common_Cursor" );
    this->cursorClass = cursor.Succeeded() ? cursor.Class : nullptr;
}

void AFistWorldController::BeginPlay( void )
{
    if( !this->cursorClass )
    {
        UE_LOG( LogTemp, Display, TEXT( "Failed to set cursor" ) );
        return;
    }
    UWorld* world = this->GetWorld();
    this->SetMouseCursorWidget( EMouseCursor::Default, UUserWidget::CreateWidgetInstance( *world, this->cursorClass, "Mouse Cursor" ) );
}
