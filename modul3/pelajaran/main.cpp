#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Algoritma dan Pemrograman";
    string kodepel = "ALG";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
