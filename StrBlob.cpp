//
// Created by Ryan on 07/12/2017.
//

#include "StrBlob.h"
#include "StrBlobPtr.h"

using std::vector;
using std::string;
using std::make_shared;

int main() {

}

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

