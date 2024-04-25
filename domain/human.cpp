#include <string>
#include "date_time.h"
#include <stdexcept>
#include "human.h"

namespace ctch1330::domain
{
    // this constructor is copied from what before was a Student constructor. 
    Human::Human(int id, std::string first_name, std::string last_name, int born_year) :
    id_{id},
    first_name_{first_name},
    last_name_{last_name}
    {
        if (born_year < 0 || born_year > DateTime::GetCurrentDateTime().year )
        {
            throw std::invalid_argument("born year can't be ngative");
        }        
        born_year_ = born_year;
    } 

}
