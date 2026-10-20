
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
