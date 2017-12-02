#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;

//
// Created by Ryan on 27/11/2017.
//
int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *e = &arr[10];

    for (int *b = arr; b != e; ++b) {
        std::cout << *b << std::endl;
    }

    for (int *b = std::begin(arr); b != std::end(arr); ++b) {
        std::cout << *b << std::endl;
    }

    int *p = &arr[2];
    int j = p[1]; //arr[3]
    int k = p[-2]; //arr[0]

    std::vector<int> v(arr, std::end(arr));
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    int a[5];
    for (int i = 0; i < v.size(); i++) {
        a[i] = v[i];
    }
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;

    const char *cp = "Hello World";
    if (cp && *cp){
        cout << *cp << endl;
    }
}