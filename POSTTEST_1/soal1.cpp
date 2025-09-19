#include <iostream>
using namespace std;

void balik(int* arr, int size) {
    int mulai = 0;
    int akhir = size - 1;
    
    while (mulai < akhir) {

        int temp = *(arr + mulai);
        *(arr + mulai) = *(arr + akhir);
        *(arr + akhir) = temp;
        
        mulai++;
        akhir--;
    }
}

int main() {
    const int size = 7;
    int arr[size];
    
    cout << "Isi array dengan kelipatan 3:" << endl;
    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 3; 
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    
    cout << "\nsebelum dibalik:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    balik(arr, size);
    
    cout << "setelah dibalik:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}