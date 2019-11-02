// Fill out your copyright notice in the Description page of Project Settings.

#include "PopupMenuWidget.h"

bool UPopupMenuWidget::OverrideShowMouseCursor( bool& showMouseCursor )
{
    showMouseCursor = true;
    return true;
}