//
// Created by Ryan on 15/12/2017.
//

#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include "../Sales_data.h"

template<typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
};

template<typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F()) {
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
};

template<>
int compare(const char *const &p1, const char *const &p2) {
    return std::strcmp(p1, p2);
}

template<typename R, typename T1, typename T2>
R sum(T1 a, T2 b) {
    return (R) a + b;
};

template<typename It>
auto fcn(It beg, It end) -> decltype(*beg) {
    return *beg;
}

template<typename It>
auto fcn2(It beg, It end) -> typename std::remove_reference<decltype(*beg)>::type {
    return *beg;
}

template<typename T>
void f3(T &&val) {
    T t = val;
}

template<typename T>
void f(T &&);

template<typename T>
void f(const T &);

template<typename T>
typename std::remove_reference<T>::type &&move(T &&t) {
    return static_cast<typename std::remove_reference<T>::type &&>(t);
}

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2) {
    f(t2, t1);
};

template<typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
    f(t2, t1);
};

template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
};

template<typename T>
std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T>
std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

std::string debug_rep(char *p) {
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    return debug_rep(std::string(p));
}

template<typename T>
std::ostream &print(std::ostream &os, const T &t) {
    return os << t;
}

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &... rest) {
    os << t << ", ";
    return print(os, rest...);
};

template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args &... rest) {
    return print(os, debug_rep(rest)...);
}

namespace std {
    template<>
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;

        size_t operator()(const Sales_data &s) const {
            return hash<string>()(s.bookNo) ^
                   hash<unsigned>()(s.units_sold) ^
                   hash<double>()(s.revenue);
        }
    };
}

int main() {
    auto val3 = sum<long long>(1, (long) 1);
}