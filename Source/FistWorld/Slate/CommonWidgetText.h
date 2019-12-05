// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "CommonWidgetText.generated.h"

UCLASS()
class FISTWORLD_API UCommonAliFontText : public UTextBlock
{
    GENERATED_BODY()

public:
    UCommonAliFontText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

protected:
    void SetFontSize( int32 size ) noexcept;
    void InitContent( const FText& text, int32 defSize );

private:
    static FSlateFontInfo g_ali_font;
};

/**
 * 
 */

UCLASS()
class FISTWORLD_API UCommonConfirmText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    UCommonConfirmText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UCommonCancelText : public UCommonAliFontText
{
	GENERATED_BODY()
	
public:
    UCommonCancelText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};
