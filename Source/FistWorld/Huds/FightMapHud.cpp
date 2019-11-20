// Copyright 2019

#include "FightMapHud.h"
#include "UObject/ConstructorHelpers.h"

AFightMapHud::AFightMapHud( const FObjectInitializer& ObjectInitializer ) : ACommonMapHud( ObjectInitializer )
{
    static ConstructorHelpers::FClassFinder<USysMenuWidget> sysmenuwidget( TEXT( "/Game/Levels/Res_lv_Fight/Widget_Fight_SysMenu" ) );
    sysmenuClass = sysmenuwidget.Succeeded() ? sysmenuwidget.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UConfirmBackWidget> confirmback( TEXT( "/Game/Levels/Res_lv_Fight/Widget_Fight_ConfirmBack" ) );
    confirmbackClass = confirmback.Succeeded() ? confirmback.Class : nullptr;
}
