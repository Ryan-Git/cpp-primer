//
// Created by Ryan on 11/12/2017.
//

#ifndef CPP_PRIMER_STRVEC_H
#define CPP_PRIMER_STRVEC_H


#include <string>

class StrVec {
public:

    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr){}

    StrVec(const StrVec &);

    StrVec(StrVec &&s) noexcept ;

    StrVec &operator=(const StrVec &) noexcept ;

    StrVec &operator=(StrVec &&) noexcept ;

    ~StrVec();

    void push_back(const std::string &);

    void push_back(std::string &&);

    size_t size() const { return first_free - elements; }

    size_t capacity() const { return cap - elements; }

    std::string *begin() const { return elements; }

    std::string *end() const { return first_free; }

private:
    std::allocator<std::string> alloc;

    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }

    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);

    void free();

    void reallocate();

    std::string *elements;
    std::string *first_free;
    std::string *cap;
};


#endif //CPP_PRIMER_STRVEC_H
