//
// Created by Ryan on 01/12/2017.
//

#ifndef CPP_PRIMER_SCREEN_H
#define CPP_PRIMER_SCREEN_H


#include <string>
#include "Window_mgr.h"

class Screen {
    friend void Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type Pos;

    Screen() = default;

    Screen(Pos ht, Pos wd) : Screen(ht, wd, ' ') {}

    Screen(Pos ht, Pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const {
        return contents[cursor];
    }

    Pos get_cursor() const {
        return cursor;
    }

    char get(Pos ht, Pos wd) const;

    Screen &move(Pos r, Pos c);

    Screen &set(char);

    Screen &set(Pos, Pos, char);

    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

    static const std::string Screen::*data() {
        return &Screen::contents;
    }

    Screen &home();

    Screen &forward();

    Screen &back();

    Screen &up();

    Screen &down();

    using Action = Screen &(Screen::*)();
    enum Directions {
        HOME, FORWARD, BACK, UP, DOWN
    };
    Screen& move(Directions);

private:
    Pos cursor = 0;
    Pos height = 0, width = 0;
    std::string contents;
    static Action Menu[];

    void do_display(std::ostream &os) const {
        os << contents;
    }
};


#endif //CPP_PRIMER_SCREEN_H
