#include "student.h"


namespace ctch1330::domain
{
    Student::Student(int id, std::string first_name, std::string last_name, int born_year, bool is_active)
    : Human(id, first_name, last_name, born_year), // notice a call to base constructor
    is_active_{is_active}
    {}

    int Student::AddCredits(int new_credits)
    {
        return credits_earned_ += new_credits;
    }

    std::string Student::QuickInformation() const
    { 
        // notice here this derived class Student can equally access members from base Human or this derived Student class
        return std::to_string( Id() ) + ". " + FirstName() + " " + LastName()+ ", age: "+ std::to_string( Age() ) + ", credits: " + std::to_string( Credits() ); 
    }    



}