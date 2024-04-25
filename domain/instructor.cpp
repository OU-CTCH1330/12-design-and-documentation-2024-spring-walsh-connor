#include <string>
#include "../src/constants.h"
#include "instructor.h"

namespace ctch1330::domain
{
    // can use Student.cpp constructor as an example when implementing Instructor
    Instructor::Instructor(int id, std::string first_name, std::string last_name, int born_year, ctch1330::SubjectArea subject_area)
    : Human(id, first_name, last_name, born_year),
    subject_area_{subject_area}
    {}

    // pay attention to spec in ReadMe and test.cpp to produce correct output by this override
    std::string Instructor::QuickInformation() const
    {
        return std::to_string( Id() ) + ". " +FirstName() + " " + LastName()+ ", age: "+ std::to_string( Age() ) + ", subject area: " + ctch1330::SubjectAreaToString( Area() ); 
    }
}


