#include <iostream>
using namespace std;

void tukar(int x, int y) {
    int temp;
    
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4, b = 6;
    cout << "Nilai a sebelum tukar: " << a << endl;
    cout << "Nilai b sebelum tukar: " << b << endl;

    tukar(a, b);

    cout << "Nilai a setelah tukar: " << a << endl;
    cout << "Nilai b setelah tukar: " << b << endl;

    return 0;
}