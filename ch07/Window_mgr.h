//
// Created by Ryan on 01/12/2017.
//

#ifndef CPP_PRIMER_WINDOW_MGR_H
#define CPP_PRIMER_WINDOW_MGR_H

#include <vector>

class Screen;

class Window_mgr {

public:
    using ScreenIndex = std::vector<Screen>::size_type;

    Window_mgr() = default;

    explicit Window_mgr(const Screen &s);

    void clear(ScreenIndex i);

    ScreenIndex addScreen(const Screen&);

private:
    std::vector<Screen> screens;
};


#endif //CPP_PRIMER_WINDOW_MGR_H
