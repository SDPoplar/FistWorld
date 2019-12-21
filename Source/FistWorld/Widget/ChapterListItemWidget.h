// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IUserObjectListEntry.h"
#include "ChapterListItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UChapterListItemWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
    UChapterListItemWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

protected:
    UFUNCTION( BlueprintImplementableEvent, Category = ObjectListEntry )
    void OnListItemObjectSet( UObject* ListItemObject );

    UFUNCTION( BlueprintCallable )
    FText GetChapterName() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetChapterDescribe() const noexcept;

    UFUNCTION( BlueprintCallable )
    void BindChapter( UObject* item );

    UFUNCTION( BlueprintCallable )
    bool IsChapterSelected() const noexcept;

    bool IsChapterBinded() const noexcept;

    class UChapterIns* m_o_chap;
};
