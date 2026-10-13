#include <iostream>
#include "matriks.h"
using namespace std;

void tampilArray(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarNilai(int *p1, int *p2) {
    int sementara = *p1;
    *p1 = *p2;
    *p2 = sementara;
}
