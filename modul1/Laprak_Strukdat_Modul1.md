# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Mohammad Rafly Firmansyah - 109082500202</p>

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut. 

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;

    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian = " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian = " << a / b << endl;
    } else {
        cout << "Pembagian tidak dapat dilakukan karena pembagi 0" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
 https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul1/unguided/unguided1.png

##### Output 2
https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul1/unguided/unguided1.2.png

Program unguided 1 diatas berfungsi untuk menerima dua bilangan bertipe float, kemudian menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100 

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka == 0) {
        cout << "nol";
    }
    else if (angka == 1) {
        cout << "satu";
    }
    else if (angka == 2) {
        cout << "dua";
    }
    else if (angka == 3) {
        cout << "tiga";
    }
    else if (angka == 4) {
        cout << "empat";
    }
    else if (angka == 5) {
        cout << "lima";
    }
    else if (angka == 6) {
        cout << "enam";
    }
    else if (angka == 7) {
        cout << "tujuh";
    }
    else if (angka == 8) {
        cout << "delapan";
    }
    else if (angka == 9) {
        cout << "sembilan";
    }
    else if (angka == 10) {
        cout << "sepuluh";
    }
    else if (angka == 11) {
        cout << "sebelas";
    }
    else if (angka == 12) {
        cout << "dua belas";
    }
    else if (angka == 13) {
        cout << "tiga belas";
    }
    else if (angka == 14) {
        cout << "empat belas";
    }
    else if (angka == 15) {
        cout << "lima belas";
    }
    else if (angka == 16) {
        cout << "enam belas";
    }
    else if (angka == 17) {
        cout << "tujuh belas";
    }
    else if (angka == 18) {
        cout << "delapan belas";
    }
    else if (angka == 19) {
        cout << "sembilan belas";
    }
    else if (angka == 20) {
        cout << "dua puluh";
    }
    else if (angka < 100) {
        int puluhan = angka / 10;
        int satuan = angka % 10;

        if (puluhan == 2)
            cout << "dua puluh";
        else if (puluhan == 3)
            cout << "tiga puluh";
        else if (puluhan == 4)
            cout << "empat puluh";
        else if (puluhan == 5)
            cout << "lima puluh";
        else if (puluhan == 6)
            cout << "enam puluh";
        else if (puluhan == 7)
            cout << "tujuh puluh";
        else if (puluhan == 8)
            cout << "delapan puluh";
        else if (puluhan == 9)
            cout << "sembilan puluh";

        if (satuan == 1)
            cout << " satu";
        else if (satuan == 2)
            cout << " dua";
        else if (satuan == 3)
            cout << " tiga";
        else if (satuan == 4)
            cout << " empat";
        else if (satuan == 5)
            cout << " lima";
        else if (satuan == 6)
            cout << " enam";
        else if (satuan == 7)
            cout << " tujuh";
        else if (satuan == 8)
            cout << " delapan";
        else if (satuan == 9)
            cout << " sembilan";
    }
    else if (angka == 100) {
        cout << "seratus";
    }
    else {
        cout << "Angka tidak valid";
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul1/unguided2/unguided2_1.png

##### Output 2
https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul1/unguided2/unguided2_2.png

Program unguided 2 diatas berfungsi untuk menerima bilangan bulat positif dari 0 sampai 100, kemudian menampilkan angka tersebut dalam bentuk tulisan.

### 3. Buatlah program yang dapat memberikan input dan output seperti di gambar. 

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {

        for (int j = n; j > i; j--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul1/unguided3/unguided3_1.png

##### Output 2
https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul1/unguided3/unguided3_2.png

Program unguided3 digunakan untuk membuat pola angka berbentuk mirror berdasarkan nilai input n.

## Kesimpulan
Berdasarkan ketiga soal yang telah dikerjakan, dapat disimpulkan bahwa pemrograman C++ dapat digunakan untuk menyelesaikan berbagai permasalahan dengan menerapkan konsep dasar seperti input, output, tipe data, operasi aritmatika, percabangan, dan perulangan. Pada soal pertama, digunakan tipe data float untuk melakukan operasi penjumlahan, pengurangan, perkalian, dan pembagian. Pada soal kedua, digunakan percabangan untuk mengubah angka menjadi bentuk tulisan. Sedangkan pada soal ketiga, digunakan perulangan untuk menghasilkan pola angka berbentuk mirror. Melalui ketiga latihan tersebut, pemahaman mengenai dasar-dasar pemrograman C++ menjadi lebih baik, terutama dalam penggunaan variabel, cin, cout, if-else, dan for.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
