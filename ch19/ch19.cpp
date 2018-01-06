//
// Created by Ryan on 04/01/2018.
//
#include <cstddef>
#include <cstdlib>
#include <new>
#include <string>
#include <functional>
#include "../ch07/Screen.h"

void *operator new(std::size_t size) {
    if (void *mem = malloc(size))
        return mem;
    else
        throw std::bad_alloc();
}

void operator delete(void *mem) noexcept {
    free(mem);
}

using Action = char (Screen::*)(Screen::Pos, Screen::Pos) const;

Screen &action(Screen &s, Action a = &Screen::get) {
    (s.*a)(0, 0);
    return s;
}

int main() {
    using namespace std;
    const string Screen::*pdata;
    pdata = Screen::data();

    Screen myScreen, *pScreen = &myScreen;
    auto s = myScreen.*pdata;
    s = pScreen->*pdata;

    auto pmf = &Screen::get_cursor;

    char (Screen::*pmf2)(Screen::Pos, Screen::Pos) const;
    pmf2 = &Screen::get;

    Screen::Pos c1 = (pScreen->*pmf)();
    char c2 = (myScreen.*pmf2)(0, 0);

    Action get = &Screen::get;

    action(myScreen);
    action(myScreen, get);
    action(myScreen, &Screen::get);

    vector<string> svec;
    function<bool (const string&)> fcn = &string::empty;
    find_if(svec.begin(), svec.end(), fcn);

    find_if(svec.begin(), svec.end(), mem_fn(&string::empty));

    auto f = mem_fn(&string::empty);
    f(*svec.begin());
    f(&svec[0]);
}