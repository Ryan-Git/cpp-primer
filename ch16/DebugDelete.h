//
// Created by Ryan on 31/12/2017.
//

#ifndef CPP_PRIMER_DEBUGDELETE_H
#define CPP_PRIMER_DEBUGDELETE_H


#include <ostream>
#include <iostream>

class DebugDelete {

public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}

    template<typename T>
    void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

private:
    std::ostream &os;
};


#endif //CPP_PRIMER_DEBUGDELETE_H
