#include "constants.h"

namespace ctch1330
{
    std::string SubjectAreaToString(SubjectArea subject_area)
    {
        switch (subject_area)
        {
        case SubjectArea::kUnknown: return "Uknown";
        case SubjectArea::kMath: return "Math";
        case SubjectArea::kEnglish: return "English";
        case SubjectArea::kComputerScience: return "ComputerScience";

        default:
            break;
        }
    }

}