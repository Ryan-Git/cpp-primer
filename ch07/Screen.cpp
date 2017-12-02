//
// Created by Ryan on 01/12/2017.
//

#include "Screen.h"

inline Screen &Screen::move(Pos r, Pos c) {
    Pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(Pos r, Pos c) const {
    Pos row = r * width;
    return contents[row + c];
}

Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(Pos r, Pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}
