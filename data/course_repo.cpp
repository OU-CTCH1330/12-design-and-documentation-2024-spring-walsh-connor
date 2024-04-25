#include "course_repo.h"
#include <stdexcept>
#include <iostream>
#include <tuple>

namespace ctch1330::data
{

    Student* CourseRepository::GetStudentsForCourse(int course_id)
    {
        Student* student_ptr = new Student();   // dummy initiation for next line
        Student** students = &student_ptr;      // will allocate correct array size after getting preliminary count
        *students = nullptr;                    
        int* current_row = new int{0};          // index when parsing currently fetched row
        std::tuple<Student**, int*> callback_parameter = {students, current_row};
        std::string course_id_string = std::to_string(course_id);
        std::string sql = 
"select count(*) from course_student where course_id = " + course_id_string +"; \
select s.* \
    from \
        course_student cs \
        inner join students s \
        on cs.student_id = s.id \
    where cs.course_id = " + course_id_string +";";
        char* error_message = new char();
        sqlite3** db_connection = new sqlite3*();
        CourseRepository::GetConnection(db_connection);
        int query_result = sqlite3_exec(*db_connection, sql.c_str(), CourseRepository::GetStudentsForCourseCallback, &callback_parameter, &error_message);
        CourseRepository::CloseConnection(*db_connection);
        delete current_row;
        delete error_message;

        if( query_result == SQLITE_OK )
        {
            return *students;
        } 
        else 
        {
            std::cout << error_message << std::endl;
            sqlite3_free(error_message);
            throw std::runtime_error( "Error occured while retrieving students from database for course" );
        }
    }

    int CourseRepository::GetStudentsForCourseCallback(void* result, int argc, char** argv, char** azColName)
    {
        std::tuple<Student**, int*>* callback_parameter = (std::tuple<Student**, int*>*)result;
        auto [students_ptr, current_row] = *callback_parameter;
        if (!(*students_ptr))
        {  
            int return_size = std::strtol(argv[0], nullptr, 10);
            *students_ptr = new Student[return_size];
            return 0;
        }

        Student* students = *students_ptr;
        int id = std::strtol(argv[0], nullptr, 10);
        std::string first_name = argv[1];
        std::string last_name = argv[2];
        int born_year = std::strtol(argv[3], nullptr, 10);
        bool is_active = std::strtol(argv[4], nullptr, 10);
        bool credits_earned = std::strtol(argv[5], nullptr, 10);
        ctch1330::Residency residency = (ctch1330::Residency)std::strtol(argv[6], nullptr, 10);
        students[(*current_row)++] = Student(id, first_name, last_name, born_year, is_active);
        return 0;   // 0 return required by sqlite api for fetching next row. nonzero will signal abortion
    }

    Course CourseRepository::GetCourseById(int course_id)
    {
        Course* course = new Course(0, "", 0, 0);
        std::string course_id_string = std::to_string(course_id);
        std::string sql = "select * from courses where id = " + course_id_string +" limit 1;";
        char* error_message = new char();
        sqlite3** db_connection = new sqlite3*();
        CourseRepository::GetConnection(db_connection);
        int query_result = sqlite3_exec(*db_connection, sql.c_str(), CourseRepository::GetCourseByIdCallback, course, &error_message);
        CourseRepository::CloseConnection(*db_connection);
        delete error_message;

        if( query_result == SQLITE_OK )
        {
            Student* students = GetStudentsForCourse(course_id);
            course->Students(students);
            return *course;
        } 
        else 
        {
            std::cout << error_message << std::endl;
            sqlite3_free(error_message);
            throw std::runtime_error( "Error occured while retrieving students from database for course" );
        }

    }

    int CourseRepository::GetCourseByIdCallback(void* result, int argc, char** argv, char** azColName)
    {
        Course* course = (Course*)result;
        int id = std::strtol(argv[0], nullptr, 10);
        std::string course_name = argv[1];
        int semester_id = std::strtol(argv[2], nullptr, 10);
        int credits = std::strtol(argv[3], nullptr, 10);
        *course = Course(id, course_name, semester_id, credits);
        return 0;

    }


}