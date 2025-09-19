// soal3.cpp
#include <iostream>
using namespace std;

const int jumlah = 5;
struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};


//halo
int main() {
    Mahasiswa mahasiswa[jumlah];

    cout << "masukkan data mahasiswa:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "\nmahasiswa ke-" << (i + 1) << ":" << endl;
        cout << "nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "nim: ";
        getline(cin, mahasiswa[i].nim);
        cout << "ipk: ";
        cin >> mahasiswa[i].ipk;
        cin.ignore(); 
    }

    // Cari mahasiswa dengan IPK tertinggi
    int indeksTertinggi = 0;
    for (int i = 1; i < jumlah; i++) {
        if (mahasiswa[i].ipk > mahasiswa[indeksTertinggi].ipk) {
            indeksTertinggi = i;
        }
    }


    cout << "\nmahasiswa dengan IPK tertinggi:" << endl;
    cout << "nama: " << mahasiswa[indeksTertinggi].nama << endl;
    cout << "nim: " << mahasiswa[indeksTertinggi].nim << endl;
    cout << "ipk: " << mahasiswa[indeksTertinggi].ipk << endl;

    return 0;
}