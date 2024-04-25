#pragma once

#include <string>
#include "../src/constants.h"
#include "human.h"

namespace ctch1330::domain
{
    class Instructor : public Human
    {
        public:

            Instructor(int id, std::string first_name, std::string last_name, int born_year, ctch1330::SubjectArea subject_area);

            // here we take advantage of a fact that this derived class can have a behavior that is richer, 
            // more appropriate to its nature than it's base "mere" Human. see Implementation in cpp file.
            std::string QuickInformation() const override;

            // accessors
            ctch1330::SubjectArea Area() const { return subject_area_; }
            void Area(ctch1330::SubjectArea subject_area) { subject_area_ = subject_area; }

        private: 

            ctch1330::SubjectArea subject_area_ = SubjectArea::kUnknown;
    };
}


