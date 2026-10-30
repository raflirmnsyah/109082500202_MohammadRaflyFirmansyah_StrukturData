# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Mohammad Rafly Firmansyah - 109082500202</p>

## Dasar Teori
Doubly Linked list adalah linked list yang masing – masing elemen nya memiliki 2 successor, yaitu successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen sesudahnya (next).  

## Guided 

### 1. Doublylist

```C++
Doublylist.h
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct barang{
    string kode;
    string nama;
    int tahun;
};

using infotype = barang;
struct elmlist;
using address = elmlist*;
struct elmlist{ infotype info; address prev; address next; };
struct list {address first; address last;};

void CreateList(list &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address R, address P);
void insertBefore(list &L, address R, address P);
void printInfo(const list &L);
address findElm(const list &L, const string &kode);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address prec, address &P);
void deleteBefore(list &L, address succ, address &P);
#endif

Doublylist.cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;

    P->info = x;
    P->next = NULL;
    P->prev = NULL;

    return P;
}

void dealokasi(List &L, address P) {
    if (P != NULL) {
        if (P == L.First) {
            L.First = P->next;
        }

        if (P == L.Last) {
            L.Last = P->prev;
        }

        if (P->prev != NULL) {
            P->prev->next = P->next;
        }

        if (P->next != NULL) {
            P->next->prev = P->prev;
        }

        delete P;
    }
}

void insertLast(List &L, address P) {
    if (P != NULL) {
        P->next = NULL;
        P->prev = NULL;

        if (L.First == NULL) {
            L.First = P;
            L.Last = P;
        } else {
            P->prev = L.Last;
            L.Last->next = P;
            L.Last = P;
        }
    }
}

void printInfo(List L) {
    address P = L.First;

    if (P == NULL) {
        cout << "List kosong." << endl;
        return;
    }

    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << endl;

        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;

    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }

        P = P->next;
    }

    return NULL;
}

void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;

        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.First = P->next;
            L.First->prev = NULL;
        }

        P->next = NULL;
        P->prev = NULL;
    } else {
        P = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.Last != NULL) {
        P = L.Last;

        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.Last = P->prev;
            L.Last->next = NULL;
        }

        P->next = NULL;
        P->prev = NULL;
    } else {
        P = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;

        Prec->next = P->next;

        if (P->next != NULL) {
            P->next->prev = Prec;
        }

        P->next = NULL;
        P->prev = NULL;
    } else {
        P = NULL;
    }
}

main.cpp
#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P;
    address Prec;

    CreateList(L);

    // Data kendaraan pertama
    x.nopol = "D001";
    x.warna = "hitam";
    x.thnBuat = 90;
    insertLast(L, alokasi(x));

    // Data kendaraan kedua
    x.nopol = "D003";
    x.warna = "putih";
    x.thnBuat = 70;
    insertLast(L, alokasi(x));

    // Nomor polisi D001 dimasukkan kembali
    x.nopol = "D001";
    x.warna = "merah";
    x.thnBuat = 80;

    if (findElm(L, x.nopol) != NULL) {
        cout << "Nomor polisi sudah terdaftar." << endl;
    } else {
        insertLast(L, alokasi(x));
    }

    // Data kendaraan keempat
    x.nopol = "D004";
    x.warna = "kuning";
    x.thnBuat = 90;
    insertLast(L, alokasi(x));

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    // Mencari nomor polisi D001
    cout << "=== PENCARIAN KENDARAAN ===" << endl;
    P = findElm(L, "D001");

    if (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data kendaraan tidak ditemukan." << endl;
    }

    // Menghapus kendaraan D003
    cout << "\n=== MENGHAPUS DATA D003 ===" << endl;

    P = findElm(L, "D003");

    if (P != NULL) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            Prec = P->prev;
            deleteAfter(Prec, P);
        }

        if (P != NULL) {
            cout << "Data dengan nomor polisi D003 berhasil dihapus."
                 << endl;
            delete P;
        }
    } else {
        cout << "Data kendaraan tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST SETELAH PENGHAPUSAN" << endl;
    printInfo(L);

    // Membersihkan seluruh elemen list
    while (L.First != NULL) {
        deleteFirst(L, P);

        if (P != NULL) {
            delete P;
        }
    }

    return 0;
}
```
File Doublylist.h dan Doublylist.cpp digunakan untuk membangun struktur data Doubly Linked List. Pada Doublylist.h, terdapat struktur barang yang menyimpan kode, nama, dan tahun barang. Kemudian, struktur elmlist digunakan untuk menyimpan informasi barang serta dua pointer, yaitu prev untuk menunjuk elemen sebelumnya dan next untuk menunjuk elemen berikutnya. Struktur list memiliki pointer first dan last untuk menunjukkan elemen pertama dan terakhir. File ini juga berisi deklarasi fungsi untuk membuat list, menambahkan, mencari, menampilkan, dan menghapus data. Sementara itu, Doublylist.cpp berisi implementasi fungsi-fungsi tersebut. CreateList digunakan untuk membuat list kosong, alokasi untuk membuat elemen baru, dealokasi untuk menghapus elemen dari memori, insertFirst dan insertLast untuk menambahkan elemen, insertAfter dan insertBefore untuk menyisipkan elemen pada posisi tertentu, printInfo untuk menampilkan data, serta findElm untuk mencari barang berdasarkan kode. Fungsi deleteFirst, deleteLast, deleteAfter, dan deleteBefore digunakan untuk menghapus elemen sesuai posisinya. Dengan fungsi-fungsi tersebut, data dalam Doubly Linked List dapat dikelola dan dihubungkan secara dua arah.

## Unguided 

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”.Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address .Hapus elemen dengan nomor polisi D003 dengan procedure delete. - procedure deleteFirst( input/output L : List,  P : address ) - - procedure deleteLast( input/output L : List,  P : address ) procedure deleteAfter( input Prec : address,  input/output P : address ) 

```C++
Doublylist.h

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

typedef struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
} infotype;

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(List &L, address P);
void printInfo(List L);
void insertLast(List &L, address P);

address findElm(List L, string nopol);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif

Doublylist.cpp
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;

    P->info = x;
    P->next = NULL;
    P->prev = NULL;

    return P;
}

void dealokasi(List &L, address P) {
    if (P != NULL) {
        if (P == L.First) {
            L.First = P->next;
        }

        if (P == L.Last) {
            L.Last = P->prev;
        }

        if (P->prev != NULL) {
            P->prev->next = P->next;
        }

        if (P->next != NULL) {
            P->next->prev = P->prev;
        }

        delete P;
    }
}

void insertLast(List &L, address P) {
    if (P != NULL) {
        P->next = NULL;
        P->prev = NULL;

        if (L.First == NULL) {
            L.First = P;
            L.Last = P;
        } else {
            P->prev = L.Last;
            L.Last->next = P;
            L.Last = P;
        }
    }
}

void printInfo(List L) {
    address P = L.First;

    if (P == NULL) {
        cout << "List kosong." << endl;
        return;
    }

    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << endl;

        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;

    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return P;
        }

        P = P->next;
    }

    return NULL;
}

void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;

        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.First = P->next;
            L.First->prev = NULL;
        }

        P->next = NULL;
        P->prev = NULL;
    } else {
        P = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.Last != NULL) {
        P = L.Last;

        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.Last = P->prev;
            L.Last->next = NULL;
        }

        P->next = NULL;
        P->prev = NULL;
    } else {
        P = NULL;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;

        Prec->next = P->next;

        if (P->next != NULL) {
            P->next->prev = Prec;
        }

        P->next = NULL;
        P->prev = NULL;
    } else {
        P = NULL;
    }
}

main.cpp
#include "Doublylist.h"

int main() {
    List L;
    infotype x;
    address P;
    address Prec;

    CreateList(L);

    // Data kendaraan pertama
    x.nopol = "D001";
    x.warna = "hitam";
    x.thnBuat = 90;
    insertLast(L, alokasi(x));

    // Data kendaraan kedua
    x.nopol = "D003";
    x.warna = "putih";
    x.thnBuat = 70;
    insertLast(L, alokasi(x));

    // Nomor polisi D001 dimasukkan kembali
    x.nopol = "D001";
    x.warna = "merah";
    x.thnBuat = 80;

    if (findElm(L, x.nopol) != NULL) {
        cout << "Nomor polisi sudah terdaftar." << endl;
    } else {
        insertLast(L, alokasi(x));
    }

    // Data kendaraan keempat
    x.nopol = "D004";
    x.warna = "kuning";
    x.thnBuat = 90;
    insertLast(L, alokasi(x));

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    // Mencari nomor polisi D001
    cout << "=== PENCARIAN KENDARAAN ===" << endl;
    P = findElm(L, "D001");

    if (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data kendaraan tidak ditemukan." << endl;
    }

    // Menghapus kendaraan D003
    cout << "\n=== MENGHAPUS DATA D003 ===" << endl;

    P = findElm(L, "D003");

    if (P != NULL) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            Prec = P->prev;
            deleteAfter(Prec, P);
        }

        if (P != NULL) {
            cout << "Data dengan nomor polisi D003 berhasil dihapus."
                 << endl;
            delete P;
        }
    } else {
        cout << "Data kendaraan tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST SETELAH PENGHAPUSAN" << endl;
    printInfo(L);

    // Membersihkan seluruh elemen list
    while (L.First != NULL) {
        deleteFirst(L, P);

        if (P != NULL) {
            delete P;
        }
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program Unguided ini merupakan implementasi struktur data Doubly Linked List yang digunakan untuk menyimpan dan mengelola data kendaraan. Pada file Doublylist.h, terdapat struktur kendaraan yang memiliki atribut nopol untuk menyimpan nomor polisi, warna untuk menyimpan warna kendaraan, dan thnBuat untuk menyimpan tahun pembuatan kendaraan. Selanjutnya, struktur ElmList digunakan untuk menyimpan informasi kendaraan serta dua pointer, yaitu next dan prev yang menghubungkan setiap elemen secara dua arah. Struktur List memiliki pointer First dan Last untuk menunjukkan elemen pertama dan terakhir. File ini juga berisi deklarasi fungsi untuk membuat list, mengalokasikan dan menghapus elemen, menambahkan data, menampilkan data, mencari kendaraan berdasarkan nomor polisi, serta menghapus elemen berdasarkan posisinya.

Pada file Doublylist.cpp, seluruh fungsi yang telah dideklarasikan diimplementasikan. Fungsi CreateList digunakan untuk membuat list kosong dengan mengatur First dan Last menjadi NULL, sedangkan alokasi digunakan untuk membuat elemen baru dan menyimpan data kendaraan. Fungsi insertLast digunakan untuk menambahkan kendaraan pada akhir list dengan menghubungkan pointer prev dan next. Fungsi printInfo digunakan untuk menampilkan seluruh data kendaraan, sedangkan findElm digunakan untuk mencari kendaraan berdasarkan nomor polisi. Selain itu, terdapat fungsi deleteFirst, deleteLast, dan deleteAfter yang digunakan untuk menghapus elemen pertama, terakhir, maupun elemen setelah posisi tertentu. Fungsi dealokasi digunakan untuk melepaskan elemen dari memori sekaligus memperbaiki hubungan antar-elemen.

Pada file main.cpp, program utama digunakan untuk menguji fungsi-fungsi Doubly Linked List dengan memasukkan beberapa data kendaraan, yaitu D001, D003, dan D004. Program juga mencoba memasukkan kembali nomor polisi D001 untuk menguji apakah data yang sama sudah terdaftar, kemudian melakukan pencarian kendaraan dengan nomor polisi D001 dan menghapus kendaraan dengan nomor polisi D003. Setelah proses penghapusan, program menampilkan kembali data kendaraan yang tersisa. Terakhir, seluruh elemen yang masih terdapat dalam list dihapus untuk membersihkan memori sebelum program berakhir. Melalui program ini, dapat dipahami bagaimana Doubly Linked List digunakan untuk menambah, mencari, menampilkan, dan menghapus data kendaraan secara terstruktur.

## Kesimpulan
Berdasarkan praktikum Modul 6, dapat disimpulkan bahwa Doubly Linked List merupakan struktur data yang setiap elemennya memiliki dua pointer, yaitu next untuk menunjuk ke elemen berikutnya dan prev untuk menunjuk ke elemen sebelumnya. Dengan struktur tersebut, proses penelusuran data dapat dilakukan dari dua arah, baik dari awal ke akhir maupun sebaliknya. Melalui praktikum ini, mahasiswa mempelajari cara membuat list, menambahkan data, mencari data, menampilkan data, serta menghapus elemen. Selain itu, praktikum ini membantu memahami penggunaan pointer dan pengelolaan memori dalam struktur data secara lebih mendalam.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
