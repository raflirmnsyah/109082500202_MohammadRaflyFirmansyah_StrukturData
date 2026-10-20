# <h1 align="center">Laporan Praktikum Modul 4 - Singly     Linked List (Bagian Pertama)</h1>
<p align="center">Mohammad Rafly Firmansyah - 109082500202</p>

## Dasar Teori
Linked list adalah salah satu bentuk struktur data berupa serangkaian elemen data yang saling berkait dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dalam Linked list bisa berupa data tunggal atau data majemuk. Data tunggal merupakan data yang hanya terdiri dari satu data, misalnya: nama bertipe string. Sedangkan data majemuk  merupakan sekumpulan data yang di dalamnya terdiri dari berbagai tipe data, misalnya: Data Mahasiswa, terdiri dari Nama bertipe string, NIM bertipe long integer, dan Alamat bertipe string.  

### A. Singly Linked List <br/>
Singly Linked list merupakan model ADT Linked list yang hanya memiliki satu arah pointer. 
#### 1. Pembentukan Komponen-Komponen List 
A. Pembentukan List Adalah sebuah proses untuk membetuk sebuah list baru. Biasanya nama fungsi yang digunakan createList(). Fungsi ini akan mengeset nilai awal list yaitu first(list) dan last(list) dengan nilai Nil. 
B. Pengalokasian Memori Adalah proses untuk mengalokasikan memori untuk setiap elemen data yang ada dalam list. Fungsi yang biasanya digunakan adalah nama fungsi yang biasa digunakan alokasi().
C. Dealokasi Untuk menghapus sebuah memory address yang tersimpan atau telah dialokasikan dalam bahasa pemrograman C digunakan syntax free, sedangkan pada C++ digunakan syntax delete
D. Pengecekan List Adalah fungsi untuk mengecek apakah list tersebut kosong atau tidak. Akan mengembalikan nilai true jika list kosong dan nilai false jika list tidak kosong. Fungsi yang digunakan adalah isEmpty(). 
#### 2. Insert
A. Insert First Merupakan metode memasukkan elemen data ke dalam list yang diletakkan pada awal list. 
B. Insert Last Merupakan metode memasukkan elemen data ke dalam list yang diletakkan pada akhir list. 
C. Insert After Merupakan metode memasukkan data ke dalam list yang diletakkan setelah node tertentu yang ditunjuk oleh user.
#### 3. View
Merupakan operasi dasar pada list yang menampilkan isi node/simpul dengan suatu penelusuran list. Mengunjungi setiap node kemudian menampilkan data yang tersimpan pada node tersebut. 
#### 4. Delete
A. Delete First Adalah pengambilan atau penghapusan sebuah elemen pada awal list.  
B. Delete Last Merupakan pengambilan atau penghapusan suatu elemen dari akhir list. 
C. Delete After Merupakan pengambilan atau penghapusan node setelah node tertentu. 
D. Delete Elemen P→next = Q→next; Q→next = Nil; return(P); Atau dealokasi(P); Adalah operasi yang digunakan untuk menghapus dan membebaskan memori yang dipakai oleh elemen tersebut. 
#### 5. Update
Merupakan operasi dasar pada list yang digunakan untuk meng-update data yang ada di dalam list. Dengan operasi update ini kita dapat meng-update data-data node yang ada di dalam list. 

## Guided 

### 1. Mahasiswa

```C++
list.h
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan nama alias address untuk pointer ke struct node

struct node { //node untuk isi dari linked list, isi setiap node adalah data dan pointer ke node berikutnya
    dataMahasiswa isidata; //menyimpan data mahasiswa
    address next; //pointer ke node berikutnya
};

struct linkedlist { //struct untuk linked list, menyimpan pointer ke node pertama
    address first; //pointer ke node pertama
};

//semua function dan procedure yang digunakan untuk linked list
bool isEmpty(linkedlist list); 
void createlist(linkedlist &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printlist(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address Prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nblist(linkedlist list);
void deletelist(linkedlist &list);

#endif

list.cpp
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist list) {
    if (list.first == Nil) {
        return true;
    } else {
        return false;
    }
}

void createlist(linkedlist &list) {
    list.first = Nil;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &list, address nodeBaru) {
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedlist &list, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &list, address nodeBaru) {
    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &list) {
    address nodeHapus;
    if (isEmpty(list) == false) {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &list) {
    address nodeHapus, nodePrev;

    if (isEmpty(list) == false) {
        nodeHapus = list.first;

        if (nodeHapus->next == Nil) {
            list.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedlist &list, address nodeHapus, address nodePrev) {
    if (isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printlist(linkedlist list) {
    if (isEmpty(list)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << " . NIM : " << nodeBantu->isidata.nim
                 << " . Usia : " << nodeBantu->isidata.umur << endl;

            nodeBantu = nodeBantu->next;
        }
    }
}

int nblist(linkedlist list) {
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deletelist(linkedlist &list) {
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List berhasil dihapus." << endl;
}

main.cpp
#include"list.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist list;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createlist(list);

    dataMahasiswa mhs;

    nodeA = alokasi("Alice", "12345", 20);
    nodeB = alokasi("Bob", "67890", 21);
    nodeC = alokasi("Charlie", "54321", 22);
    nodeD = alokasi("David", "98765", 23);
    nodeE = alokasi("Eve", "13579", 24);
  
    insertFirst(list, nodeA);
    insertLast(list, nodeB);
    insertAfter(list, nodeC, nodeA);
    insertAfter(list, nodeD, nodeC);
    insertLast(list, nodeE);

    cout << "--ISI LIST SETELAH DI LAKUKAN INSERT--" << endl;
    printlist(list);
    cout << "Jumlah node: " << nblist(list) << endl;
    cout << endl;

    delFirst(list)  ;
    delLast(list);
    delAfter(list, nodeD, nodeC);

    cout << "--ISI LIST SETELAH DI LAKUKAN DELETE--" << endl;
    printlist(list);
    cout << "Jumlah node: " << nblist(list) << endl;
    cout << endl;

    deletelist(list);
    cout << "--ISI LIST SETELAH DI LAKUKAN HAPUS LIST--" << endl;
    printlist(list);
    cout << "Jumlah node: " << nblist(list) << endl;
    cout << endl;

    return 0;
}
```
Program di atas digunakan untuk mengelola data mahasiswa menggunakan struktur data Singly Linked List. Langkah awal, program membuat list kosong menggunakan createlist(), kemudian membuat lima node yang berisi nama, NIM, dan umur mahasiswa menggunakan alokasi(). Selanjutnya, data dimasukkan ke dalam list menggunakan insertFirst(), insertLast(), dan insertAfter(). Setelah itu, program menampilkan isi list dan jumlah node menggunakan printlist() dan nblist(). Program kemudian melakukan penghapusan node menggunakan delFirst(), delLast(), dan delAfter(), lalu menampilkan kembali data yang tersisa. Terakhir, deletelist() digunakan untuk menghapus seluruh node sehingga list menjadi kosong dan jumlah node menjadi 0.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”, Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”, Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut. 

```C++
Singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address P);
int nbList(List L);
void deleteList(List &L);

#endif

Singlylist.cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L) {
    if (L.First != Nil) {
        address P = L.First;
        L.First = P->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.First == Nil) {
        return;
    }

    address P = L.First;

    if (P->next == Nil) {
        L.First = Nil;
        dealokasi(P);
    } else {
        while (P->next->next != Nil) {
            P = P->next;
        }

        address Q = P->next;
        P->next = Nil;
        dealokasi(Q);
    }
}

void deleteAfter(List &L, address P) {
    if (P != Nil && P->next != Nil) {
        address Q = P->next;
        P->next = Q->next;
        dealokasi(Q);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;

    while (P != Nil) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    while (L.First != Nil) {
        deleteFirst(L);
    }
}

main.cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    deleteList(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul4/singlylist/soa1.png)

Program ini digunakan untuk membuat dan menampilkan data menggunakan struktur data Singly Linked List. Langkah awal, program membuat list kosong menggunakan CreateList(), kemudian membuat node berisi nilai 2, 0, 8, 12, dan 9 menggunakan alokasi(). Setiap node dimasukkan ke bagian awal list menggunakan insertFirst(), sehingga urutan data yang ditampilkan menjadi 9, 12, 8, 0, dan 2. Selanjutnya, printInfo() digunakan untuk menampilkan seluruh data pada linked list.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). 

```C++
karena di soal 2 ini kita hanya perlu merubah main.cpp saja, jadi saya hanya mencantumkan main.cpp nya saja.

main.cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, L.First);

    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);

    cout << endl;
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/raflirmnsyah/109082500202_MohammadRaflyFirmansyah_StrukturData/blob/master/modul4/singlylist/soal2.png)

Program ini digunakan untuk menghapus node dan menghitung jumlah node yang tersisa pada Singly Linked List. Langkah awal, program membuat linked list yang berisi data 9, 12, 8, 0, dan 2. Selanjutnya, deleteFirst() digunakan untuk menghapus node pertama, yaitu 9, deleteLast() untuk menghapus node terakhir, yaitu 2, dan deleteAfter() untuk menghapus node 8. Setelah penghapusan dilakukan, printInfo() menampilkan data yang tersisa, yaitu 12 dan 0. Fungsi nbList() digunakan untuk menghitung jumlah node yang tersisa sebanyak 2 node, sedangkan deleteList() digunakan untuk menghapus seluruh node sehingga jumlah node menjadi 0.

## Kesimpulan
Pada Modul 4 ini, kita mempelajari implementasi ADT Singly Linked List menggunakan bahasa pemrograman C++. Materi ini mencakup pembuatan list kosong, alokasi dan dealokasi memori, penyisipan node di awal list, penghapusan node di awal, akhir, dan setelah node tertentu, serta perhitungan jumlah node. Melalui praktikum ini, kita dapat memahami penggunaan pointer untuk menghubungkan setiap node dan mengetahui cara mengelola data secara dinamis menggunakan linked list.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
