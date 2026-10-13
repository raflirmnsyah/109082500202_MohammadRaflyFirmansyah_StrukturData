#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namapel = namapel;
    pel.kodepel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran input_pel) {
    cout << "nama pelajaran : " << input_pel.namapel << endl;
    cout << "nilai : " << input_pel.kodepel << endl;
}
