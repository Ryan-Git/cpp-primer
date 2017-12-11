#include <string>

//
// Created by Ryan on 08/12/2017.
//
class HasPtrAsVal {
public:
    friend inline void swap(HasPtrAsVal& l, HasPtrAsVal& r){
        using std::swap;
        swap(l.ps, r.ps);
        swap(l.i, r.i);
    }

    explicit HasPtrAsVal(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

    HasPtrAsVal(const HasPtrAsVal &p) : ps(new std::string(*p.ps)), i(p.i) {}

    HasPtrAsVal &operator=(HasPtrAsVal rhs) {
        swap(*this, rhs);
        return *this;
    }

//    HasPtrAsVal &operator=(const HasPtrAsVal &rhs) {
//        auto *t = new std::string(*rhs.ps);
//        delete ps;
//        ps = t;
//        i = rhs.i;
//        return *this;
//    }

    ~HasPtrAsVal() { delete ps; }

private:
    std::string *ps;
    int i;
};

class HasPtrAsPtr {
public:
    HasPtrAsPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}

    HasPtrAsPtr(const HasPtrAsPtr &p) : ps(p.ps), i(p.i), use(p.use) {
        ++*use;
    }

    HasPtrAsPtr &operator=(const HasPtrAsPtr &rhs) {
        ++*rhs.use;
        if (--*use == 0) {
            delete ps;
            delete use;
        }

        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }

    ~HasPtrAsPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }

private:
    std::string *ps;
    int i;
    std::size_t *use;
};