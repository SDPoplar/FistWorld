// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupMenuWidget.h"
#include "Engine/DataTable.h"
#include "CreateGameWidget.generated.h"

USTRUCT( BlueprintType )
struct FCreatableChapter : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY( BlueprintReadOnly )
    int id;

    UPROPERTY( BlueprintReadOnly )
    FString name;

    UPROPERTY( BlueprintReadOnly )
    FString describe;
};

class UComboBoxString;

/**
 * 
 */
UCLASS()
class FISTWORLD_API UCreateGameWidget : public UPopupMenuWidget
{
	GENERATED_BODY()
public:
    UFUNCTION( BlueprintCallable )
    TArray<FCreatableChapter> GetAllChapters();

    UFUNCTION( BlueprintCallable )
    TArray<FString> DebugDatatable();

    UFUNCTION( BlueprintCallable )
    UComboBoxString* RefreshChapter( UComboBoxString* holder );

protected:
    static UDataTable* GetChapterTable();
    static UDataTable* chapters;
};
