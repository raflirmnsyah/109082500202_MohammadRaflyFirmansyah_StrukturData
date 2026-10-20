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