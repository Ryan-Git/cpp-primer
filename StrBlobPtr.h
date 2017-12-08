//
// Created by Ryan on 08/12/2017.
//

#ifndef CPP_PRIMER_STRBLOBPTR_H
#define CPP_PRIMER_STRBLOBPTR_H


#include <memory>
#include "StrBlob.h"

class StrBlobPtr {
public:

    StrBlobPtr(): curr(0){}

    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}

    std::string& deref() const;

    StrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};


#endif //CPP_PRIMER_STRBLOBPTR_H
