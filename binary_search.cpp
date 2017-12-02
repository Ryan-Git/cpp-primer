//
// Created by Ryan on 27/11/2017.
//
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

int binary_search(vector<int> seq, int target) {
    auto begin = seq.begin(), end = seq.end();
    auto mid = begin + (end - begin) / 2;

    while (mid != end && *mid != target) {
        if (target < *mid) {
            end = mid;
        } else {
            begin = mid;
        }
        mid = begin + (end - begin) / 2;
    }

    if (mid != end) {
        return *mid;
    } else {
        return -1;
    }
}

int main() {
    std::vector<int> seq{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 8;

    cout << binary_search(seq, target) << endl;
}
