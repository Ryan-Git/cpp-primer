//
// Created by Ryan on 23/12/2017.
//

#ifndef CPP_PRIMER_BLOBPTR_H
#define CPP_PRIMER_BLOBPTR_H

#include <memory>
#include "Blob.h"

template<typename T>
class BlobPtr {

public:
    BlobPtr() : curr(0) {}

    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    T &operator*() const {
        auto p = check(curr, "deference past end");
        return (*p)[curr];
    }

    BlobPtr &operator++();
    BlobPtr operator++(int);
    BlobPtr &operator--();

private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;

    std::weak_ptr<std::vector<T>> wptr;

    std::size_t curr;
};


#endif //CPP_PRIMER_BLOBPTR_H
