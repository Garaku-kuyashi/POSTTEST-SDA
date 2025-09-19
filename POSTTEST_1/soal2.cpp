// soal2.cpp
#include <iostream>
using namespace std;

int main() {
    const int size = 3;
    int matriks[size][size];

    cout << "Mengisi matriks 3x3:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matriks[i][j] = (i * size + j + 1);
            cout << "matriks[" << i << "][" << j << "] = " << matriks[i][j] << endl;
        }
    }

    cout << "\nMatriks:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }

    int diagonalUtama = 0;
    for (int i = 0; i < size; i++) {
        diagonalUtama += matriks[i][i];
    }

    int diagonalSekunder = 0;
    for (int i = 0; i < size; i++) {
        diagonalSekunder += matriks[i][size - 1 - i];
    }


    int hasil = diagonalUtama + diagonalSekunder;

    cout << "\nDiagonal Utama: ";
    for (int i = 0; i < size; i++) {
        cout << matriks[i][i] << " ";
    }
    cout << "→ Jumlah = " << diagonalUtama << endl;

    cout << "Diagonal Sekunder: ";
    for (int i = 0; i < size; i++) {
        cout << matriks[i][size - 1 - i] << " ";
    }
    cout << "→ Jumlah = " << diagonalSekunder << endl;

    cout << "Total diagonal utama + sekunder = " << total << endl;

    return 0;
}