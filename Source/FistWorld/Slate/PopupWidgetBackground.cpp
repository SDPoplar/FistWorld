// Copyright 2019

#include "PopupWidgetBackground.h"
#include "UObject/ConstructorHelpers.h"
#include "PanelSlot.h"
#include "CanvasPanelSlot.h"

UPopBgBase::UPopBgBase( const FObjectInitializer& ObjectInitializer )
    : UImage( ObjectInitializer )
{
    auto slot = Cast<UCanvasPanelSlot>( this->Slot );
    if( !slot )
    {
        return;
    }
    auto layout = slot->GetLayout();
    layout.Offsets = FMargin( 0, 0 );
    layout.Anchors.Minimum = FVector2D( 0, 0 );
    layout.Anchors.Maximum = FVector2D( 1, 1 );
    slot->SetLayout( layout );
    slot->ZOrder = -1;
}

UPopBgTitle::UPopBgTitle( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgtitle( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_title" ) );
    if( popbgtitle.Succeeded() )
    {
        this->SetBrushFromTexture( popbgtitle.Object );
    }
}

UPopBgTitleWithExit::UPopBgTitleWithExit( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgtitlewe( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_title_with_exit" ) );
    if( popbgtitlewe.Succeeded() )
    {
        this->SetBrushFromTexture( popbgtitlewe.Object );
    }
}

UPopBgCenterTitle::UPopBgCenterTitle( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgctitle( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_center_title" ) );
    if( popbgctitle.Succeeded() )
    {
        this->SetBrushFromTexture( popbgctitle.Object );
    }
}

UPopBgBodyRV::UPopBgBodyRV( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgbodyrv( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_body_rv" ) );
    if( popbgbodyrv.Succeeded() )
    {
        this->SetBrushFromTexture( popbgbodyrv.Object );
    }
}

UPopBgBottom::UPopBgBottom( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgbottom( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_bottom" ) );
    if( popbgbottom.Succeeded() )
    {
        this->SetBrushFromTexture( popbgbottom.Object );
    }
}

UPopBgBottomAllLineButton::UPopBgBottomAllLineButton( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgbottomalb( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_bottom_all_line_button" ) );
    if( popbgbottomalb.Succeeded() )
    {
        this->SetBrushFromTexture( popbgbottomalb.Object );
    }
}

UPopBgBottomSingleButton::UPopBgBottomSingleButton( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgbottomsb( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_bottom_single_button" ) );
    if( popbgbottomsb.Succeeded() )
    {
        this->SetBrushFromTexture( popbgbottomsb.Object );
    }
}

UPopBgBottomDoubleButton::UPopBgBottomDoubleButton( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgbottomdb( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_bottom_double_button" ) );
    if( popbgbottomdb.Succeeded() )
    {
        this->SetBrushFromTexture( popbgbottomdb.Object );
    }
}

UPopBgBottomCenterSingleButton::UPopBgBottomCenterSingleButton( const FObjectInitializer& ObjectInitializer )
    : UPopBgBase( ObjectInitializer )
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> popbgbottomcsb( TEXT( "/Game/Levels/Res_lv_Common/PopupWidget/texture_bg_widget_bottom_center_single_button" ) );
    if( popbgbottomcsb.Succeeded() )
    {
        this->SetBrushFromTexture( popbgbottomcsb.Object );
    }
}
