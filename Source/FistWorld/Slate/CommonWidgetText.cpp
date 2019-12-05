// Copyright 2019

#include "CommonWidgetText.h"
#include "Static/Lang/CommonWidget.h"
#include "Engine/Font.h"
#include "UObject/ConstructorHelpers.h"

FSlateFontInfo UCommonAliFontText::g_ali_font( nullptr, 16 );

UCommonAliFontText::UCommonAliFontText( const FObjectInitializer& ObjectInitializer ) : UTextBlock( ObjectInitializer )
{
    if( !g_ali_font.FontObject )
    {
        static ConstructorHelpers::FObjectFinder<UFont> alifont( TEXT( "/Game/Fonts/Alibaba-PuHuiTi-Regular_Font" ) );
        if( alifont.Succeeded() )
        {
            g_ali_font.FontObject = alifont.Object;
        }
    }
}

void UCommonAliFontText::InitContent( const FText& content, int32 defSize )
{
    this->SetFontSize( defSize );
    this->SetText( content );
}

void UCommonAliFontText::SetFontSize( int32 size ) noexcept
{
    FSlateFontInfo f( g_ali_font );
    f.Size = size;
    this->SetFont( f );
}

UCommonConfirmText::UCommonConfirmText( const FObjectInitializer& ObjectInitializer ) : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtCommonConfirmText, 24 );
}

UCommonCancelText::UCommonCancelText( const FObjectInitializer& ObjectInitializer ) : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtCommonCancelText, 24 );
}
