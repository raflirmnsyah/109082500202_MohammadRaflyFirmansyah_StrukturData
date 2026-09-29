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