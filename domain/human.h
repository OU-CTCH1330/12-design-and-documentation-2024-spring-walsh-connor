#pragma once

#include <string>
#include "date_time.h"


namespace ctch1330::domain
{
    /// @brief Base class. 
    class Human
    {
        public:

            // common traits of all humans (student or instructor) have been moved to a common base class

            void Id(int id) { id_ = id; }
            int Id() const { return id_; }

            void FirstName(std::string first_name) { first_name_ = first_name; }
            std::string FirstName() const { return first_name_; }

            void LastName(std::string last_name) { last_name_ = last_name; }
            std::string LastName() const { return last_name_; }

            /// @brief Produces age from year born
            /// @return Age of the human
            int Age() const { return DateTime::GetCurrentDateTime().year - born_year_ ; } 

            /// @brief Produces a quick information about the human, corresponding to the nature of the derived class
            /// @return quick information about human
            virtual std::string QuickInformation() const { return FirstName() + " " + LastName(); }
            // notice symtax for (non-pure) virtual function                

        protected:

            // placing constructor(s) in non-public section makes class abstract
            Human(){}

            Human(int id, std::string first_name, std::string last_name, int born_year);

            // we place data in non-public access section, since they are not meant to be 
            // directly worked with from outside of the inheritance chain
            int id_{0};
            std::string first_name_{""};
            std::string last_name_{""};
            int born_year_{0};

        private:

            // we are careful not to place members in private area, since this is a base class and 
            // more likely inherited classes will have to work with the data. 

    };    
}
