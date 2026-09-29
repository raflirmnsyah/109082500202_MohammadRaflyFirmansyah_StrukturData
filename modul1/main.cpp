#include <iostream>
using namespace std;

int main() {
    // cout << "Hello, World!" << endl;

    //int a;
    //cin >> a;
    // cout << "You entered: " << a << endl;

    int a = 5; 
    if (a > 0) {
        cout << "a is positive" << endl;
    } else if (a < 0) {
        cout << "a is negative" << endl;
    } else {
        cout << "a is zero" << endl;
    }
    return 0;
}