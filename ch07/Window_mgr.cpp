//
// Created by Ryan on 01/12/2017.
//

#include "Window_mgr.h"
#include "Screen.h"

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::Window_mgr(const Screen &s) : screens{Screen(24, 80, ' ')} {}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}
