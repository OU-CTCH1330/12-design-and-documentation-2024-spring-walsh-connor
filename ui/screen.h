#pragma once

#include <ncurses.h>
#include <string>

namespace ctch1330::ui
{
    class Screen
    {
        public:
            static void Initialize();
            static void Exit();

            static void Render();

            // accessors
            static std::string Title(){ return title_; }
            static void Title(std::string title){ title_ = title; }

            static std::string Status(){ return status_; }
            static void Status(std::string status){ status_ = status; }



        protected:
            static std::string title_;
            static std::string status_;
    };


}