#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp;

    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp;

    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 2, b = 7, c = 4;

    cout << "=== Nilai Awal ===" << endl;
    cout << "Nilai a sebelum tukar: " << a << endl;
    cout << "Nilai b sebelum tukar: " << b << endl;
    cout << "Nilai c sebelum tukar: " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "\n=== Setelah tukar dengan POINTER ===" << endl;
    cout << "Nilai a setelah tukar: " << a << endl;
    cout << "Nilai b setelah tukar: " << b << endl;
    cout << "Nilai c setelah tukar: " << c << endl;

    tukarReference(a, b, c);

    cout << "\n=== Setelah tukar dengan REFERENCE ===" << endl;
    cout << "Nilai a setelah tukar: " << a << endl;
    cout << "Nilai b setelah tukar: " << b << endl;
    cout << "Nilai c setelah tukar: " << c << endl;

    return 0;
}