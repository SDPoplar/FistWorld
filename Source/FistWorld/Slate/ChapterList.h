// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ListView.h"
#include "ChapterList.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UChapterList : public UListView
{
	GENERATED_BODY()

public:
    UChapterList( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    int GetSelectedChapterId();
	
};
