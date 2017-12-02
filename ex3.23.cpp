#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> v(3, 5);
    for (int &i : v) {
        i *= 2;
    }

    for (int i:v) {
        cout << i << " ";
    }
    cout << endl;
}
