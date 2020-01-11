// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Chapter.generated.h"

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

class UChapter
{
public:
    UChapter();
    virtual ~UChapter() {}

    bool SetChapterId( int id, bool loadData = false );
    virtual int GetChapterId() const noexcept;
    virtual FString GetChapterName() const noexcept;

protected:
    static UDataTable* GetChapterData();

    int m_n_chap_id;
    FString m_s_chap_name;

private:
    FCreatableChapter* FindChapterData() const noexcept;
    static UDataTable* g_chapters;
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UChapterIns : public UObject, public UChapter
{
	GENERATED_BODY()

public:
    UChapterIns( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    FText GetChapterDescribe() const noexcept;
    static TArray<UChapterIns*> GetAllChapterIns( UObject* getter );

    UChapterIns& operator =( const FCreatableChapter& data );
protected:
    FText m_s_describe;
};
