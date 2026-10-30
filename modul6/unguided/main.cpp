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
