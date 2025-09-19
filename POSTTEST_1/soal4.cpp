#include <iostream>
using namespace std;

void tukar(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    int *px = &x;
    int *py = &y;

    cout << "\nSebelum ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    
    tukar(&px, &py);

    cout << "\nSesudah ditukar:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}