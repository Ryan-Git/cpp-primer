#include <iostream>
#include <vector>
#include <functional>
#include <sys/socket.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void pointers() {
    int ival = 42;
    int *p = &ival;

    double dval = 0.0;
    double *pd = &dval;
    double *pd2 = pd;

    std::cout
            << *p << '\n'
            << p << '\n'
            << &dval << '\n'
            << *pd << '\n'
            << pd << '\n'
            << &pd << '\n'
            << *pd2 << '\n'
            << pd2 << '\n'
            << &pd2 << '\n'

            << std::endl;
}

void references() {

    int ival = 1024;
    int &refVal = ival;
    int &refVal3 = refVal;
    int i = refVal;

    std::cout << &refVal << "\n";
    std::cout << &refVal3 << "\n";
    std::cout << refVal3 << "\n";
    std::cout << &i << "\n";
    std::cout << i << "\n";
    std::cout << refVal << std::endl;
}

#include "Sales_data.h"
#include "ch07/Screen.h"

int header() {
    Sales_data data1, data2;
    double price = 0;
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    std::cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (data1.bookNo == data2.bookNo) {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";

        if (totalCnt != 0) {
            std::cout << totalRevenue / totalCnt << std::endl;
        } else {
            std::cout << "(no sales)" << std::endl;
        }
        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}

void test_string() {
    string s1;
    string s2 = s1;
    string s3 = "hiys";
    string s4(10, 'c');
    string s5 = "hiya";
    string s6("hiya");
    string s7(10, 'c');
    string s8 = string(10, 'c');

    string s;
    cin >> s;
    cout << s << endl;

    string str("Hello World!!!");
    for (char &c : str) {
        c = static_cast<char>(toupper(c));
    }
    cout << str << endl;
}

void test_vector() {
    vector<int> ivec{1, 2, 3};
    auto b = ivec.begin(), e = ivec.end();
    cout << *b << endl;

    ++b;
    cout << *b << endl;

    string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = static_cast<char>(toupper(*it));
    }
    cout << s << endl;

    auto it3 = ivec.cbegin(); //constant iterator

    vector<string> text{"abc", "123", "", "def"};
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        cout << *it << endl;
    }
}

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

int main() {
//    references();
//    pointers();
//    return header();
//    test_vector();

    auto check6 = bind(check_size, std::placeholders::_1, 6);
    bool b1 = check6(string("hello"));

    Screen myScreen(5, 3);
    const Screen blank(5, 3);
    myScreen.set('#').display(cout);
    blank.display(cout);
    return 0;
}