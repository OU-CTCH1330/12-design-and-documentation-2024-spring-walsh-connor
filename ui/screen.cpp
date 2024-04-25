#include "screen.h"

namespace ctch1330::ui
{
    std::string Screen::title_;
    std::string Screen::status_;

    void Screen::Initialize()
    {
        initscr();  // initialize curses screen
        box(stdscr, 0, 0);
        echo();   // no echoing to term
        raw();      // enable buffering, ctrl-* controls
        keypad(stdscr, true);   // F1, arrows, etc enabled
        // printw("LMS");
        refresh();  // render screen with updated content
    }

    void Screen::Exit()
    {
        endwin();
    }

    void Screen::Render()
    {
        mvaddstr(0, 2, Title().c_str());
        refresh();
        getch();
    }

}