# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Mohammad Rafly Firmansyah - 109082500202</p>

## Dasar Teori
ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT merupakan definisi STATIK. 

## Guided 

### 1. Mahasiswa

```C++
mahasiswa.h
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);

#endif 

mahasiswa.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai1 = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
} 

float rata2(mahasiswa m) {
    return float (m.nilai1 + m.nilai2) / 2;
}

main.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata nilai: " << rata2(mhs) << endl;
    return 0;
}
```
Pemrograman di atas digunakan untuk menyimpan data mahasiswa berupa NIM, nilai 1, dan nilai 2 menggunakan `struct`. Prosedur `inputMhs()` digunakan untuk memasukkan data mahasiswa, sedangkan fungsi `rata2()` digunakan untuk menghitung dan mengembalikan nilai rata-rata dari kedua nilai tersebut. Hasil rata-rata kemudian ditampilkan ke layar melalui `main.cpp`.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas. 

```C++
mahasiswa.h
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

mahasiswa.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

void inputMahasiswa(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "Nama: ";
        cin >> ws;
        getline(cin, mhs[i].nama);

        cout << "NIM: ";
        cin >> mhs[i].nim;

        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;

        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(
            mhs[i].uts, mhs[i].uas, mhs[i].tugas
        );
    }
}

void tampilMahasiswa(Mahasiswa mhs[], int n) {
    cout << "\n=== DATA MAHASISWA ===" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nNama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "UTS: " << mhs[i].uts << endl;
        cout << "UAS: " << mhs[i].uas << endl;
        cout << "Tugas: " << mhs[i].tugas << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
}

main.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    Mahasiswa mhs[MAX];
    int n;

    cout << "Jumlah mahasiswa (maksimal 10): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 0;
    }

    inputMahasiswa(mhs, n);
    tampilMahasiswa(mhs, n);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Gambar 1](https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul3/datamahasiswa/gambar1.png)

##### Output 2
![Screenshot Output Gambar 2](https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul3/datamahasiswa/gambar2.png)

Pemrograman di atas digunakan untuk menyimpan, menghitung, dan menampilkan data mahasiswa yang terdiri dari nama, NIM, nilai UTS, UAS, dan tugas. Program menghitung nilai akhir menggunakan rumus 30% UTS, 40% UAS, dan 30% tugas, dengan jumlah maksimal 10 mahasiswa.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”: 
Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp” Cobalah hasil implementasi ADT pada file “main.cpp” 

```C++
pelajaran.h
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namapel;
    string kodepel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran input_pel);

#endif
pelajaran.cpp
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
main.cpp
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Pelajaran 1](https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul3/pelajaran/pelajaran1.png)

##### Output 2
![Screenshot Output Pelajaran 2](https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul3/pelajaran/pelajaran2.png)

Pemrograman di atas digunakan untuk membuat dan menampilkan data pelajaran yang terdiri dari nama pelajaran dan kode pelajaran. Fungsi create_pelajaran() digunakan untuk membuat data, sedangkan prosedur tampil_pelajaran() digunakan untuk menampilkan data pelajaran ke layar.

### 3. Buatlah program dengan ketentuan : 
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer 
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer 

```C++
matriks.h
#ifndef MATRIKS_H
#define MATRIKS_H

const int N = 3;

void tampilArray(int arr[N][N]);
void tukarNilai(int *p1, int *p2);

#endif

matriks.cpp
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

main.cpp
#include <iostream>
#include "matriks.h"
using namespace std;

int main() {
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "Array A sebelum ditukar:" << endl;
    tampilArray(A);

    cout << "\nArray B sebelum ditukar:" << endl;
    tampilArray(B);

    int *p1 = &A[0][0];
    int *p2 = &B[2][2];

    tukarNilai(p1, p2);

    cout << "\nArray A setelah ditukar:" << endl;
    tampilArray(A);

    cout << "\nArray B setelah ditukar:" << endl;
    tampilArray(B);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Mariks 1](https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul3/matriks/mariks1.png)

Pemrograman di atas digunakan untuk menampilkan dua array integer berukuran 3×3 dan menukar nilai pada posisi tertentu menggunakan pointer. Pointer digunakan untuk menunjuk alamat memori dari nilai yang akan ditukar sehingga perubahan nilai dapat langsung diterapkan pada kedua array.

## Kesimpulan
Pada modul 3 ini kita mempelajari konsep Abstract Data Type (ADT) untuk mengelola data menggunakan struktur data, fungsi, dan prosedur. Materi ini mencakup pembuatan dan pengolahan data mahasiswa untuk menghitung nilai akhir, pembuatan ADT pelajaran untuk menyimpan dan menampilkan informasi pelajaran, serta penggunaan array 2D dan pointer untuk mengakses dan menukar nilai pada array. Melalui praktikum ini, kita dapat memahami cara mengorganisasi data, memisahkan fungsi berdasarkan tugasnya, serta menggunakan pointer untuk mengubah nilai secara langsung melalui alamat memori.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
