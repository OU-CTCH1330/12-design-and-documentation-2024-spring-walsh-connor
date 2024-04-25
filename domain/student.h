#pragma once

#include <string>
#include "../src/constants.h"
#include "date_time.h"
#include "human.h"

namespace ctch1330::domain
{
    class Student : public Human    //   notice syntax for (public) inheritance
    {

        // notice derived Student class is adding data and behavior on the top of what's inherited from base Human

        public:

            Student() : Student(0, "", "", 0, true) {}
            Student(int id, std::string first_name, std::string last_name, int age, bool isActive=true);

            /// @brief inactivate the student
            void Inactivate() { is_active_ = false; };

            /// @brief activate the student
            void Activate() { is_active_ = true; };

            /// @brief get active status
            /// @return true if active, otherwise false
            bool IsActive() { return is_active_; }              

            /// @brief inspect all enrollment eligibility requirements
            /// @return true if active, otherwise false
            bool IsEligibleForEnrollment();

            /// @brief add credits to students earned credits
            /// @param new_credits new credits earned
            /// @return updated total credits earned
            int AddCredits(int new_credits);

            std::string QuickInformation() const override;

            // accessors
            int Credits() const { return credits_earned_; }
            void Credits( int credits ) { credits_earned_ = credits; }

            void Residency(ctch1330::Residency residency) { residency_ = residency; }
            ctch1330::Residency Residency() { return residency_; }


        private: 

            bool is_active_ = true;
            int credits_earned_ = 0;
            ctch1330::Residency residency_ = ctch1330::Residency::kUnknown;
    };
}


