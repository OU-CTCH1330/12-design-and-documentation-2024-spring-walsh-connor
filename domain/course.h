#pragma once

#include "student.h"

namespace ctch1330::domain
{
    class Course
    {
        public:

            Course(int id, std::string course_name, int semester_id, int credits)
            : Course(id, course_name, semester_id, credits, nullptr)
            {}

            Course(int id, std::string course_name, int semester_id, int credits, Student* students);

            ~Course(){ delete[] students_; } // we deallocate it in the 

            Student* GetPage(int page_number);

            // accessors
            int Id(){ return id_;}
            void Id(int id) { id_ = id; }

            std::string CourseName(){ return course_name_; }
            void CourseName(std::string course_name) { course_name_ = course_name; }

            int SemesterId(){ return semester_id_; }
            void SemesterId(int semester_id){ semester_id_ = semester_id; }

            int Credits(){return credits_; }
            void Credits(int credits){ credits_ = credits; }

            Student* Students(){ return students_; }
            void Students(Student* students){ students_ = students; }

            int PageSize(){ return page_size_; }
            void PageSize(int page_size) { page_size_ = page_size; }

        private:

            Student* students_;
            int id_;
            std::string course_name_;
            int semester_id_;
            int credits_;

            int page_size_ = 5;

    };
    
}
