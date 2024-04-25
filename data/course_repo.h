#pragma once

#include "../domain/student.h"
#include "../domain/course.h"
#include "repository.h"

using Student = ctch1330::domain::Student;
using Course = ctch1330::domain::Course;

namespace ctch1330::data
{
    class CourseRepository : Repository
    {
        public:



            static Course GetCourseById(int course_id);

            static Student* GetStudentsForCourse(int course_id);

            static int GetStudentsForCourseCallback(void* result, int argc, char** argv, char** azColName);
            static int GetCourseByIdCallback(void* result, int argc, char** argv, char** azColName);

        private:


    };
}