// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "Slate/ChapterList.h"
#include "CreateGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UCreateGameWidget : public UPopupWidget
{
	GENERATED_BODY()
public:
    UFUNCTION( BlueprintCallable )
    bool RefreshChapter();

    UFUNCTION( BlueprintCallable )
    bool CreateGame();

    UFUNCTION( BlueprintCallable )
    bool CanClickCreate();

    void BindParent( class UMainMenu* parent );
protected:
    UFUNCTION( BlueprintImplementableEvent )
    UChapterList* GetChapterList();

    class UMainMenu* m_parent;
};
