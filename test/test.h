#pragma once

#include <iostream>
#include "catch_amalgamated.hpp"
#include "../domain/student.h"
#include "../domain/students.h"
#include "../domain/instructor.h"
#include "../data/course_repo.h"
#include <vector>
#include <sqlite3.h> 

#define CONFIG_CATCH_MAIN

using Student = ctch1330::domain::Student;
using Students = ctch1330::domain::Students;
using Instructor = ctch1330::domain::Instructor;
using Human = ctch1330::domain::Human;
using Repository = ctch1330::data::Repository;
using CourseRepository = ctch1330::data::CourseRepository;