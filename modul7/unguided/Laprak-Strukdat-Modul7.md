# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Mohammad Rafly Firmansyah - 109082500202</p>

## Dasar Teori
Stack merupakan salah satu bentuk struktur data dimana prinsip operasi yang digunakan seperti tumpukan. Seperti halnya tumpukan, elemen yang bisa diambil terlebih dahulu adalah elemen yang paling atas, atau elemen yang pertama kali masuk, prinsip ini biasa disebut LIFO (Last In First Out). 

### A. Komponen-Komponen dalam Stack <br/>
...
#### Komponen – komponen dalam stack pada dasarnya sama dengan komponen pada Singly linked list. Hanya saja akses pada stack hanya bisa dilakukan pada awal stack saja. 

### B. Operasi-Operasi dalam Stack <br/>
...
#### Dalam stack ada dua operasi utama, yaitu operasi penyisipan (Push) dan operasi pengambilan (Pop). 
#### 1. Push Adalah operasi menyisipkan elemen pada tumpukan data. Fungsi ini sama dengan fungsi insert first pada list biasa.
#### 2. Pop Adalah operasi pengambilan data dalam list. Operasi ini mirip dengan operasi delete first dalam list linear, karena elemen yang paling pertama kali diakses adalah elemen paling atas atau elemen paling awal saja.  

## Guided 

### 1. Stack

```C++
stack.h
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
char nim[20];
char nama[20];
};

struct Stack {
infotype info[10];
int Top;
};

int isEmpty(Stack S);

void createStack(Stack &S);

void push(Stack &S, infotype X);

void pop(Stack &S, infotype &X);

void viewStack(Stack S);

#endif 

stack.cpp
#include "stack.h"

int isEmpty(Stack S) {
    if (S.Top == 0) {
        return 0; 
    } else {
        return 1; 
    }
}

void createStack(Stack &S) {
    S.Top = 0; 
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X; 
    } else {
        cout << "Stack Penuh, data tidak dapat ditambahkan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1]; 
        S.Top = S.Top - 1; 
    } else {
        cout << "Stack Kosong, tidak ada data yang dapat diambil" << endl;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "Isi Stack: " << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.info[i - 1].nim << " - " << S.info[i - 1].nama << endl;
        }
    }
}

main.cpp
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "---Push 3 Data---" << endl;
    strcpy(data.nim, "109082500202");
    strcpy(data.nama, "Andi");
    push(S, data);

    strcpy(data.nim, "109082500203");
    strcpy(data.nama, "Budi");
    push(S, data);

    strcpy(data.nim, "109082500204");
    strcpy(data.nama, "Citra");
    push(S, data);
    viewStack(S);

    cout << endl << "---Pop 1 Data---" << endl;
    pop(S, hasil);
    cout << "Data yang di ambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "---Pop sampai kosong---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil); 
    viewStack(S);

    return 0;
}
```
File stack.h digunakan untuk mendeklarasikan struktur data Stack yang berisi informasi mahasiswa berupa NIM dan nama. Selain itu, terdapat deklarasi fungsi isEmpty(), createStack(), push(), pop(), dan viewStack() yang digunakan untuk mengelola data pada Stack. File stack.cpp berisi implementasi dari fungsi-fungsi yang telah dideklarasikan pada stack.h. Fungsi isEmpty() digunakan untuk memeriksa apakah Stack kosong, createStack() untuk membuat Stack kosong, push() untuk menambahkan data, pop() untuk mengambil sekaligus menghapus data teratas, dan viewStack() untuk menampilkan seluruh isi Stack. File main.cpp digunakan untuk menjalankan dan menguji operasi Stack. Program diawali dengan membuat Stack kosong, kemudian memasukkan tiga data mahasiswa yaitu Andi, Budi, dan Citra menggunakan push(). Selanjutnya, program mengambil data menggunakan pop() hingga Stack kosong dan menampilkan isi Stack pada setiap proses.Program Guided 1 mengimplementasikan struktur data Stack menggunakan Array dengan prinsip LIFO (Last In, First Out), yaitu data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan.

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”. Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”. Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user. 

```C++
stack.h
#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &s);
void push(Stack &s, infotype x);
infotype pop(Stack &s);
void printInfo(Stack s);
void balikStack(Stack &s);

void pushAscending(Stack &s, infotype x);
void getInputStream(Stack &s);

#endif

stack.cpp
#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &s) {
    s.top = -1;
}

void push(Stack &s, infotype x) {
    if (s.top < 19) {
        s.top++;
        s.info[s.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &s) {
    if (s.top >= 0) {
        infotype x = s.info[s.top];
        s.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack s) {
    cout << "[TOP] ";

    for (int i = s.top; i >= 0; i--) {
        cout << s.info[i] << " ";
    }

    cout << endl;
}

void balikStack(Stack &s) {
    int kiri = 0;
    int kanan = s.top;

    while (kiri < kanan) {
        infotype temp = s.info[kiri];
        s.info[kiri] = s.info[kanan];
        s.info[kanan] = temp;

        kiri++;
        kanan--;
    }
}

void pushAscending(Stack &s, infotype x) {
    if (s.top < 19) {
        int i = s.top;

        while (i >= 0 && s.info[i] > x) {
            s.info[i + 1] = s.info[i];
            i--;
        }

        s.info[i + 1] = x;
        s.top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void getInputStream(Stack &s) {
    char input;

    cout << "Masukkan angka: ";

    while (cin.get(input) && input != '\n') {
        if (input >= '0' && input <= '9') {
            push(s, input - '0');
        }
    }
}

main.cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;

    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;

    balikStack(S);

    printInfo(S);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

File stack.h digunakan untuk mendeklarasikan struktur data Stack menggunakan Array dengan kapasitas maksimal 20 elemen bertipe integer. Selain itu, terdapat deklarasi fungsi createStack(), push(), pop(), printInfo(), balikStack(), pushAscending(), dan getInputStream() yang digunakan untuk mengelola data pada Stack.File stack.cpp berisi implementasi dari fungsi-fungsi yang telah dideklarasikan pada stack.h. Fungsi createStack() digunakan untuk membuat Stack kosong, push() untuk menambahkan data, pop() untuk mengambil dan menghapus data teratas, serta printInfo() untuk menampilkan isi Stack. Selain itu, terdapat fungsi balikStack() untuk membalik urutan data dan pushAscending() untuk memasukkan data secara berurutan dari kecil ke besar. Fungsi getInputStream() digunakan untuk membaca input angka dari keyboard hingga pengguna menekan Enter.File main.cpp digunakan untuk menjalankan dan menguji implementasi ADT Stack. Program diawali dengan membuat Stack kosong, kemudian memasukkan beberapa angka yaitu 3, 4, 8, 2, 3, dan 9 menggunakan fungsi pushAscending(). Setelah itu, program menampilkan isi Stack menggunakan printInfo(), kemudian membalik urutan data menggunakan balikStack() dan menampilkan kembali hasilnya.Program Unguided 1 mengimplementasikan struktur data Stack menggunakan Array dengan prinsip LIFO (Last In, First Out). Program ini juga menerapkan operasi tambahan berupa pengurutan data menggunakan pushAscending() dan pembalikan urutan Stack menggunakan balikStack().

## Kesimpulan
Berdasarkan praktikum Guided dan Unguided, dapat disimpulkan bahwa struktur data Stack dapat diimplementasikan menggunakan Array untuk menyimpan dan mengelola data dengan prinsip LIFO (Last In, First Out), yaitu data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan. Melalui praktikum ini, dipelajari berbagai operasi Stack, seperti membuat Stack, menambahkan data, menghapus data, dan menampilkan isi Stack. Selain itu, dilakukan pengembangan operasi tambahan berupa pengurutan data secara ascending dan pembalikan urutan Stack. Dengan praktikum ini, pemahaman mengenai konsep, cara kerja, serta penerapan struktur data Stack menggunakan bahasa C++ menjadi lebih baik.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
