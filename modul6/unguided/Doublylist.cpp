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
