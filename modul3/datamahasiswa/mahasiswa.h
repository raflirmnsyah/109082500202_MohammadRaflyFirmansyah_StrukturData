#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
using namespace std;

const int MAX = 10;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas);
void inputMahasiswa(Mahasiswa mhs[], int n);
void tampilMahasiswa(Mahasiswa mhs[], int n);

#endif
