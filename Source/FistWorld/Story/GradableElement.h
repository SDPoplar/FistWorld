// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include <map>
#include "GradableElement.generated.h"

UENUM( BlueprintType )
enum class EElemGrade : uint8
{
    UNKOWN = 0,
    NORMAL = 1,
    GOOD = 2,
    RARE = 3,
    LEGEND = 4,
};

/**
 * 
 */
class FISTWORLD_API GradableElement
{
public:
	GradableElement();
	virtual ~GradableElement();

    virtual EElemGrade GetGrade() const noexcept = 0;

    virtual FLinearColor GetGradeColor() const noexcept;

    static FLinearColor GetDefaultColor() noexcept;
    static FLinearColor GetColorByGrade( const EElemGrade grade ) noexcept;

private:
    static std::map<EElemGrade, FLinearColor> g_grade_color;
};
