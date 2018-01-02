//
// Created by Ryan on 23/12/2017.
//

#include "BlobPtr.h"

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}