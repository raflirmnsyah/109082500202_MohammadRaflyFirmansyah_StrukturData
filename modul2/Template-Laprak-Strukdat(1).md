# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori

### A. Array<br/>
Array merupakan kumpulan data dengan nama yang sama dan setiap elemen bertipe data sama. Untuk mengakses setiap komponen / elemen array berdasarkan indeks dari setiap elemen.
#### 1. Array Satu Dimensi Adalah array yang hanya terdiri dari satu larik data saja. 
#### 2. Array Dua Dimensi Bentuk array dua dimensi ini mirip seperti tabel. Jadi array dua dimensi bisa digunakan untuk menyimpan data dalam bentuk tabel. Terbagi menjadi dua bagian, dimensi pertama dan dimensi kedua. Cara akses, deklarasi, inisialisasi, dan menampilkan data sama dengan array satu dimensi, hanya saja indeks yang digunakan ada dua. 
#### 3. Array Berdimensi Banyak Merupakan array yang mempunyai indeks banyak, lebih dari dua. Indeks inilah yang menyatakan dimensi array. Array berdimensi banyak lebih susah dibayangkan, sejalan dengan jumlah dimensi dalam array.  

### B. Pointer<br/>
#### 1. Data dan Memori, Semua data yang ada digunakan oleh program komputer disimpan di dalam memori (RAM) komputer. Memori dapat digambarkan sebagai sebuah  array 1 dimensi yang berukuran sangat besar. Seperti layaknya array, setiap cell memory memiliki “indeks” atau “alamat” unik yang berguna untuk identitas yang biasa kita sebut sebagai “address”.
#### 2. Pointer dan Alamat, Nilai variabel a Alamat variabel a Nilai variabel j Alamat varibel j Alamat variabel arr[4] Variabel pointer merupakan dasar tipe variabel yang berisi integer dalam format heksadesimal. Pointer digunakan untuk menyimpan alamat memori variabel lain sehingga pointer dapat mengakses nilai dari variabel yang alamatnya ditunjuk.  
#### 3. Pointer dan Array, Ada keterhubungan yang kuat antara array dan pointer. Banyak operasi yang bisa dilakukan dengan array juga bisa dilakukan dengan pointer
#### 4. Pointer dan String  
A. String 
String merupakan bentuk data yang sering digunakan dalam bahasa pemrograman untuk mengolah data teks atau kalimat. Dalam bahasa C++ pada dasarnya string merupakan kumpulan dari karakter atau array dari karakter.  
B. Pointer dan String 
Sesuai dengan penjelasan di atas , misalkan ada string : "I am string" Merupakan array dari karakter. Dalam representasi internal, array diakhiri dengan karakter ‘\0’ sehingga program dapat menemukan akhir dari program. Panjang dari storage merupakan panjang dari karakter yang ada dalam tanda petik dua ditambah satu. Ketika karakter string tampil dalam sebuah program maka untuk mengaksesnya digunakan pointer karakter. Standar input/output akan menerima pointer dari awal karakter array sehingga konstanta string akan diakses oleh pointer mulai dari elemen pertama. 

### C. Fungsi<br/>
#### 1. Fungsi merupakan blok dari kode yang dirancang untuk melaksanakan tugas khusus dengan tujuan: 1. Program menjadi terstruktur, sehingga mudah dipahami dan mudah dikembangkan. Program dibagi menjadi beberapa modul yang kecil. 2. Dapat mengurangi pengulangan kode (duplikasi kode) sehingga menghemat ukuran program. Pada umumnya fungsi memerlukan masukan yang dinamakan sebagai parameter. Masukan ini selanjutnya diolah oleh fungsi. Hasil akhir fungsi berupa sebuah nilai (nilai balik fungsi). 

### D. Prosedur<br/>
#### 1. Dalam bahasa pemrograman C++, prosedur adalah istilah yang sering digunakan untuk merujuk pada fungsi yang tidak mengembalikan nilai. Dalam istilah C++, prosedur ini dikenal sebagai fungsi void. Fungsi-fungsi ini melakukan tugas tertentu tetapi tidak memberikan nilai balik (return value) kepada pemanggilnya. Sebaliknya, fungsi yang mengembalikan nilai, seperti int atau double, memberikan hasil yang dapat digunakan lebih lanjut dalam program.  

## Guided 

### 1. Array1_dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << ": " << nilai[i] << endl;
    }
    return 0;
}
```
Menampilkan nilai dari 1 hingga 5

### 2. Array2_dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };
    
    //print nilai array 2 dimensi
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl; //88
    return 0;
}
```
Script di atas digunakan untuk menampilkan seluruh isi array 2 dimensi berukuran 3×3 serta mengakses dan menampilkan salah satu elemen array secara spesifik, yaitu nilai 88.

### 3. Array3_dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };
    cout << data[0][1][2] << endl; 
    return 0;
}
```
Script di atas digunakan untuk membuat array 3 dimensi berukuran 2×2×3 dan mengakses elemen tertentu dalam array, yaitu nilai 60.

### 4. Alamat

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "nilai angka : " << angka << endl;
    cout << "Alamat angka : " << &angka << endl;
    
    return 0;
}
```
Script di atas digunakan untuk menampilkan nilai variabel angka dan mengetahui alamat memori tempat variabel tersebut disimpan.

### 5. Pointer 1

```C++
#include <iostream>
using namespace std;

int main() {
    char arr[6];
    
    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = '\0'; 

    cout << arr[3] << endl; // value
    cout << &(arr[4]) << endl; // address

    return 0;
}
```
Script di atas digunakan untuk membuat array karakter, mengisi data karakter ke dalam array, kemudian menampilkan nilai pada indeks tertentu dan alamat memori dari elemen array.

### 6. Pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "nilai angka : " << angka << endl; //100
    cout << "Alamat angka : " << &angka << endl; //address
    cout << "Isi pointer : " << pointer << endl; //address angka
    cout << "Nilai dari pointer : " << *pointer << endl; //value angka (100)

    return 0;
}
```
Script di atas digunakan untuk mempelajari pointer dengan menyimpan alamat variabel angka ke dalam pointer, kemudian menampilkan alamat tersebut dan nilai angka melalui pointer.

### 7. Array3_dimensi

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max) 
        temp_max = b;
    
    if (c > temp_max) 
        temp_max = c;
    
    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1 : ";
    cin >> x;
    cout << "Masukkan nilai 2 : ";
    cin >> y;
    cout << "Masukkan nilai 3 : ";
    cin >> z;

    cout << "Nilai maksimum : " << maks3(x, y, z) << endl;

    return 0;
}
```
Script di atas digunakan untuk menerima tiga bilangan dari pengguna, membandingkan ketiganya melalui fungsi maks3(), kemudian menampilkan bilangan yang memiliki nilai paling besar.

### 8. Array3_dimensi

```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Halo, selamat datang!" << endl;
}

int main() {
    sapa();
    return 0;
}
```
Script di atas digunakan untuk mempelajari penggunaan fungsi void, yaitu membuat fungsi yang menjalankan suatu perintah tanpa mengembalikan nilai, kemudian memanggil fungsi tersebut dari main().

### 9. Array3_dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };
    cout << data[0][1][2] << endl; 
    return 0;
}#include <iostream>
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
```
Script di atas digunakan untuk mempelajari pertukaran nilai menggunakan fungsi dengan konsep pass by value, sehingga perubahan pada parameter di dalam fungsi tidak mengubah nilai variabel aslinya di main().

### 10. Array3_dimensi

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4, b = 6;    ;
    cout << "Nilai a sebelum tukar: " << a << endl;
    cout << "Nilai b sebelum tukar: " << b << endl;

    tukar(&a, &b);

    cout << "Nilai a setelah tukar: " << a << endl;
    cout << "Nilai b setelah tukar: " << b << endl;

    return 0;
}
```
Script di atas digunakan untuk menukar nilai dua variabel secara langsung menggunakan pointer (pass by reference melalui alamat), sehingga perubahan yang dilakukan di dalam fungsi juga mengubah nilai variabel asli di main().

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3  

```C++
#include <iostream>
using namespace std;

const int N = 3;

void inputMatriks(int m[N][N], string nama) {
    cout << "Masukkan elemen matriks " << nama << " (3x3):" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cout << nama << "[" << i << "][" << j << "] = ";
            cin >> m[i][j];
        }
}

void tampilMatriks(int m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

void jumlah(int a[N][N], int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hasil[i][j] = a[i][j] + b[i][j];
}

void kurang(int a[N][N], int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hasil[i][j] = a[i][j] - b[i][j];
}

void kali(int a[N][N], int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < N; k++)
                hasil[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    int A[N][N], B[N][N], C[N][N];
    int pilihan;

    inputMatriks(A, "A");
    inputMatriks(B, "B");

    do {
        cout << "\n--- Menu Operasi Matriks 3x3 ---" << endl;
        cout << "1. Penjumlahan (A + B)" << endl;
        cout << "2. Pengurangan (A - B)" << endl;
        cout << "3. Perkalian   (A x B)" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlah(A, B, C);
                cout << "Hasil A + B:" << endl;
                tampilMatriks(C);
                break;
            case 2:
                kurang(A, B, C);
                cout << "Hasil A - B:" << endl;
                tampilMatriks(C);
                break;
            case 3:
                kali(A, B, C);
                cout << "Hasil A x B:" << endl;
                tampilMatriks(C);
                break;
            case 4:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1]!(https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul2/unguided1/unguided1_1.png)

##### Output 2
![Screenshot Output Unguided 1_2]!(https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul2/unguided1/unguided1_2.png)

Script di atas digunakan untuk membuat program operasi matriks 3×3 dengan menggunakan fungsi, yang memungkinkan pengguna memasukkan dua matriks kemudian melakukan penjumlahan, pengurangan, atau perkalian matriks dan menampilkan hasilnya.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel  

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1]!(https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul2/unguided2/unguided2_1.png)

##### Output 2
![Screenshot Output Unguided 2_2]!(https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul2/unguided2/unguided2_2.png)

Script di atas digunakan untuk mempelajari perbedaan penggunaan pointer dan reference dalam menukar nilai tiga variabel. Pointer menggunakan alamat memori dengan simbol * dan &, sedangkan reference menggunakan & pada parameter fungsi untuk langsung mengakses variabel asli.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : --- Menu Program Array ---  • Tampilkan isi array  • cari nilai maksimum • cari nilai minimum  • Hitung nilai rata - rata 

```C++
#include <iostream>
using namespace std;

const int UKURAN = 10;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void hitungRataRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    double rata = (double) total / n;
    cout << "Nilai rata-rata: " << rata << endl;
}

int main() {
    int arrA[UKURAN] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < UKURAN; i++)
                    cout << arrA[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, UKURAN) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, UKURAN) << endl;
                break;
            case 4:
                hitungRataRata(arrA, UKURAN);
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1]!(https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul2/unguided3/unguided3_1.png)

##### Output 2
![Screenshot Output Unguided 3_2]!(https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul2/unguided3/unguide3_2.png)

Script di atas digunakan untuk mengolah array berisi 10 data dengan menggunakan beberapa fungsi, yaitu menampilkan isi array, mencari nilai maksimum dan minimum, serta menghitung nilai rata-rata berdasarkan pilihan pengguna melalui menu program.

## Kesimpulan
...
Kesimpulan dari materi modul 2, dapat disimpulkan bahwa array, fungsi, pointer, dan reference dapat digunakan untuk mengolah data secara terstruktur dalam C++. Pada soal pertama, digunakan fungsi untuk melakukan operasi pada matriks seperti penjumlahan, pengurangan, dan perkalian. Pada soal kedua, dipelajari penggunaan pointer dan reference untuk menukar nilai beberapa variabel secara langsung. Pada soal ketiga, digunakan fungsi untuk mengolah array dengan mencari nilai maksimum, minimum, dan rata-rata. Dari ketiga soal tersebut, dapat dipahami bahwa penggunaan fungsi dan pointer dapat membuat program lebih terstruktur, mempermudah pengolahan data, dan memungkinkan perubahan nilai variabel secara langsung.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
