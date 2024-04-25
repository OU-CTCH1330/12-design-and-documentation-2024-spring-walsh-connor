#include "course.h"

namespace ctch1330::domain
{
    
    Course::Course(int id, std::string course_name, int semester_id, int credits, Student* students)
    : id_{id}, course_name_{course_name}, semester_id_{semester_id}, credits_{credits}, students_{students}
    {}

    Student* Course::GetPage(int page_number)
    {
        int first_entry = PageSize() * (page_number - 1);
        return Students() + first_entry;
    }


}

