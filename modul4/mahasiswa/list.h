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