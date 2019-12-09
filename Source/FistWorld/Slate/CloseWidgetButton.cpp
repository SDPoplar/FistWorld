// Copyright 2019

#include "CloseWidgetButton.h"
#include "UObject/ConstructorHelpers.h"
#include "ButtonWidgetStyle.h"
#include "Engine/Texture2D.h"

UCloseWidgetButton::UCloseWidgetButton() : UButton()
{
    FButtonStyle style;
    
    static ConstructorHelpers::FObjectFinder<UTexture2D> normal( TEXT( "/Game/Levels/Res_lv_Common/texture_btn_widget_close_normal" ) );
    if( normal.Succeeded() )
    {
        this->FillBrush( normal.Object, style.Normal );
    }
    static ConstructorHelpers::FObjectFinder<UTexture2D> hover( TEXT( "/Game/Levels/Res_lv_Common/texture_btn_widget_close_hover" ) );
    if( hover.Succeeded() )
    {
        this->FillBrush( hover.Object, style.Hovered );
    }
    static ConstructorHelpers::FObjectFinder<UTexture2D> pressed( TEXT( "/Game/Levels/Res_lv_Common/texture_btn_widget_close_press" ) );
    if( pressed.Succeeded() )
    {
        this->FillBrush( pressed.Object, style.Pressed );
    }
    static ConstructorHelpers::FObjectFinder<UTexture2D> disabled( TEXT( "/Game/Levels/Res_lv_Common/texture_btn_widget_close_disabled" ) );
    if( disabled.Succeeded() )
    {
        this->FillBrush( disabled.Object, style.Disabled );
    }
    this->SetStyle( style );
}

void UCloseWidgetButton::FillBrush( UTexture2D* texture, FSlateBrush& brush )
{
    brush.SetResourceObject( texture );
    brush.SetImageSize( FVector2D( 80, 40 ) );
    brush.DrawAs = ESlateBrushDrawType::Image;
}
