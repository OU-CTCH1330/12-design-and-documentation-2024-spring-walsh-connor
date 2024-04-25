#pragma once

#include <string>

namespace ctch1330
{
    enum class Residency
    {
        kUnknown = 0,
        kStateResident,
        kNonResident,
        kInternational
    };

    enum class SubjectArea
    {
        kUnknown = 0,
        kMath,
        kEnglish,
        kComputerScience
    };

    std::string SubjectAreaToString(SubjectArea subject_area);

}