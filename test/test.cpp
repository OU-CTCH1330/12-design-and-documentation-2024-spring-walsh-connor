#include "test.h"

ctch1330::domain::Student giorgi{0, "giorgi", "shonia", 1976};
ctch1330::domain::Student olga{1, "olga", "shonia", 1974};

// this is a sanbox case. 
TEST_CASE("scratch", "[scratch]")
{

	SECTION("sandbox 1")
	{
		// you can put your code in this block. you can 
		// run it by launching "Test an individual test" task
		// or debug by selecting "Debug an individual test" from debug dropdown.
		// In both cases select "scratch" when asked

		// purpose here is to provide a place to quickly test small ideas and code

		int age = 16;			// int size memory allocated, value placed in it
								// this variable is tied to that memory address
								// any future assignment will keep the same memory, put different value in it

		int* age0;				// age0 is pointing to a random, probably invalid address
								// using *age0 will likely crash the program
								// even if valid, that address containes undefined value

		int* age1 = new int;	// int size valid  memory allocated with random value in it,
								// age1 points to that memory

		age1 = &age;			// age1 repointed to a new address

		age1 = new int{17};		// on the top of above (a valid memory allocated) 
								// a specific value is initialized in it
								// age1 repointed to that

		age1 = (int*) 17;		// similar to above, with cast syntax

		age0 = new int{17};
		*age0 = 18; 			// this is assignment of value, rather than that of memory
								// age0 points to the same memory as before, but value there is replaced from 17 to 18
		
	}

}	

// this test case is for Student class, you dont have to do anything here for assignment 09.
TEST_CASE("individual student tests", "[student]")
{

	SECTION("initiation")
	{
		REQUIRE( giorgi.QuickInformation() == "0. giorgi shonia, age: 47, credits: 0" );
	}

	SECTION("credits")
	{
		giorgi.Credits(0);
		giorgi.AddCredits(3);
		giorgi.AddCredits(2);
		REQUIRE( giorgi.Credits() == 5 );

		//reset the data to avoid test contamination
		giorgi.Credits(0);
	}

	SECTION("inactivity")
	{
		giorgi.Inactivate();
		REQUIRE( giorgi.IsActive() == false );
	}

	SECTION("residency")
	{
		giorgi.Residency(ctch1330::Residency::kStateResident);
		REQUIRE( giorgi.Residency() == ctch1330::Residency::kStateResident );
	}

}	

// target class is Students
TEST_CASE("students body tests", "[students]")
{   
	// setup. test_case is executed executed individually for each SECTION below
	// thus this three lines are pre-executed before each section
	// the result is clean environment, so impact of previous sections does not contaminate the next
	Students::Reset();
	Students::AddStudent(giorgi);
	Students::AddStudent(olga);	

	// each section contains tests for a single target function. 
	// for instance target function of this section is AddStudent()
	SECTION("test AddStudent()")
	{
		REQUIRE( Students::GetStudentBodySize() == 2 );

		Students students;
		REQUIRE( students[0].QuickInformation() == "0. giorgi shonia, age: 47, credits: 0" );
	}	

	// notice, this section tests update functionality twice. 
	// once for "positive path", adding a valid update
	// the second time for negative path, for trying (and failing) an invalid update
	SECTION("test UpdateStudent()")
	{
		int student_id = 1;
		Student student{student_id, "masha", "shonia", 2006};
		bool result = Students::UpdateStudent(student);
		REQUIRE( result == true );	// update reports successful

		Student new_student;
		bool result2 = Students::GetStudentById(student_id, new_student);
		REQUIRE( new_student.QuickInformation() == "1. masha shonia, age: 17, credits: 0" );	// update was indeed successful

		// need to test a negative test
		int student_body_size = Students::GetStudentBodySize();
		Student nonexistent_student{student_body_size, "na", "na", 2000};
		bool result3 = Students::UpdateStudent(nonexistent_student);
		REQUIRE( result3 == false );	// update reports failed

	}

	// notice id search is using "pass by reference"
	// lecture for assignment review has a discussion for this
	SECTION("test GetStudentById()")
	{
		Student student;
		bool result = Students::GetStudentById(0, student);
		REQUIRE( result == true );
		REQUIRE( student.QuickInformation() == "0. giorgi shonia, age: 47, credits: 0" );
	}

	// search by name should be able to retrieve (all) matches to first and last name submitted
	// this means looping through the entire student body and collecting all matching students. 
	SECTION("test SearchStudentByName()")
	{
		auto students = Students::SearchStudentByName("olga", "shonia");
		REQUIRE( students.size() == 1 );
		REQUIRE( students[0].Id() == 1 );
	}	
}

// test case for assignment 10
// target class is Students
TEST_CASE("individual instructor tests", "[instructor]")
{   
	// we initiate instance of an instructor
	Instructor ken {0, "Ken", "Thompson", 1943, ctch1330::SubjectArea::kComputerScience};

	// but the same instance can be "sliced" as just a human (carefull!)
	Human testHuman = ken;

	// testing 
	// 1. proper initiation and 
	// 2. override implementation 

	SECTION("test initiation and QuickInformation()")
	{
		// how does Ken behave when viewed just as human? just reports his name
		// this functionality doesn't need your coding, it's already inherited from base Human class
		REQUIRE( testHuman.QuickInformation() == "Ken Thompson" );

		// how does Ken behave in his full capacity as an instrctor? 
		// should report: 0. Ken Thompson, age: 80, subject area: ComputerScience		
		// this is the output you should code to when overriding QuickInformation() in Instructor
		REQUIRE( ken.QuickInformation() == "0. Ken Thompson, age: "+ std::to_string( ken.Age() ) +", subject area: " + ctch1330::SubjectAreaToString( ctch1330::SubjectArea::kComputerScience ) );

	}
}

TEST_CASE("database tests", "[data]")
{

	SECTION("test connection initiation")
	{
		sqlite3** db_connection = new sqlite3*();
		int initiation_result = Repository::GetConnection(db_connection);
		int closing_result = Repository::CloseConnection(*db_connection);
		REQUIRE( initiation_result == 0 );
		REQUIRE( closing_result == 0) ;
	}

	SECTION("test get students for course")
	{
		Student* students = CourseRepository::GetStudentsForCourse(1);
		REQUIRE( students[0].Id() == 23 );
		REQUIRE( students[0].FirstName() == "Benjamin" );
		REQUIRE( students[1].Id() == 24 );
		REQUIRE( students[1].FirstName() == "Kathryn" );
		delete[] students;
	}

	SECTION("test get course by id")
	{
		Course course = CourseRepository::GetCourseById(1);
		REQUIRE( course.CourseName() == "CTCH 1330" );
		REQUIRE( course.Students()[0].FirstName() == "Benjamin" );
	}

	SECTION("test course get page")
	{
		Course course = CourseRepository::GetCourseById(2);
		Student*all_students_in_course = course.Students();
		REQUIRE( all_students_in_course[0].Id() == 21 );

		Student* students = course.GetPage(2);
		
		REQUIRE( students[0].Id() == 26 );	// pagination allows reading from the same instance in memory, but few entries skipped forward
	}

}