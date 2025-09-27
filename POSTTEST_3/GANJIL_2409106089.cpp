#include <iostream>
#include <string>
using namespace std;

struct Item {
    string nama_item;
    int jumlah;
    string tipe;
};

struct node {
    Item item;
    node* next;
    node* prev;
};

bool isEmpty(node* head) {
    return head == nullptr;
}

void addFirst(node*& head, node*& tail, const Item& data) {
    node* nodeBaru = new node;
    nodeBaru->item = data;
    nodeBaru->next = head;
    nodeBaru->prev = nullptr; 

    if (isEmpty(head)) {
        tail = nodeBaru;
    } else {

        head->prev = nodeBaru;
    }

    head = nodeBaru; 
    cout << "Item ditambahkan di awal." << endl;
}

void addLast(node*& head, node*& tail, const Item& data) {
    node* nodeBaru = new node;
    nodeBaru->item = data;
    nodeBaru->next = nullptr;    
    nodeBaru->prev = tail;       

    if (isEmpty(head)) {
        head = nodeBaru;
        tail = nodeBaru;
        cout << "Item ditambahkan sebagai yang pertama." << endl;
    } else {
        tail->next = nodeBaru;
        tail = nodeBaru;
        cout << "Item ditambahkan di akhir." << endl;
    }
}

void addMiddle(node*& head, node*& tail, const Item& data, int posisi) {
    if (posisi <= 1) {
        addFirst(head, tail, data);
        return;
    }

    node* temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << ">> Posisi tidak valid!" << endl;
        return;
    }

    if (temp->next == nullptr) {
        addLast(head, tail, data);
    } else {
        node* nodeBaru = new node;
        nodeBaru->item = data;
        nodeBaru->next = temp->next;      
        nodeBaru->prev = temp;            
        temp->next->prev = nodeBaru;      
        temp->next = nodeBaru;            
        cout << "Item ditambahkan di posisi ke-" << posisi << "." << endl;
    }
}

void deleteFirst(node*& head, node*& tail) {
    if (isEmpty(head)) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    node* temp = head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;       
        head->prev = nullptr;    
    }
    delete temp;
    cout << "Item pertama berhasil dihapus." << endl;
}

void deleteLast(node*& head, node*& tail) {
    if (isEmpty(head)) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    node* temp = tail;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;       
        tail->next = nullptr;   
    }
    delete temp;
    cout << "Item terakhir berhasil dihapus." << endl;
}

void deleteMiddle(node*& head, node*& tail, int posisi) {
    if (isEmpty(head)) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    if (posisi <= 1) {
        deleteFirst(head, tail);
        return;
    }

    node* temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << ">> Posisi tidak valid!" << endl;
        return;
    }

    if (temp == head) {
        deleteFirst(head, tail);
    } else if (temp == tail) {
        deleteLast(head, tail);
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        cout << "Item di posisi ke-" << posisi << " berhasil dihapus." << endl;
    }
}

void editData(node*& head, int posisi, const Item& dataBaru) {
    if (isEmpty(head)) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    node* temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << ">> Posisi tidak valid!" << endl;
        return;
    }

    cout << "Data lama:" << endl;
    cout << "nama_item: " << temp->item.nama_item << ", jumlah: " << temp->item.jumlah << ", tipe: " << temp->item.tipe << endl;
    temp->item = dataBaru;
    cout << "Data berhasil diubah!" << endl;
}

void useItem(node*& head, node*& tail) {
    if (isEmpty(head)) {
        cout << ">> Inventory kosong!" << endl;
        return;
    }

    string namaCari;
    cout << "Masukkan nama item yang ingin digunakan: ";
    cin >> namaCari;

    node* temp = head;
    bool ditemukan = false;

    while (temp != nullptr) {
        if (temp->item.nama_item == namaCari) {
            ditemukan = true;
            cout << "Item ditemukan! Jumlah sebelum: " << temp->item.jumlah << endl;
            temp->item.jumlah--;

            if (temp->item.jumlah == 0) {
                cout << "Item habis. Menghapus dari inventory..." << endl;

                if (temp == head && temp == tail) {
                    head = tail = nullptr;
                } else if (temp == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
            } else {
                cout << "Item digunakan. Jumlah tersisa: " << temp->item.jumlah << endl;
            }
            break;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << ">> Item '" << namaCari << "' tidak ditemukan." << endl;
    }
}

void display(node* head) {
    if (isEmpty(head)) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    cout << "\nDaftar Item:" << endl;
    node* temp = head;
    int nomor = 1;
    while (temp != nullptr) {
        cout << nomor << ". nama_item: " << temp->item.nama_item << ", jumlah: " << temp->item.jumlah << ", tipe: " << temp->item.tipe << endl; 
        temp = temp->next;
        nomor++;
    }
    cout << endl;
}

void lihatbelakang(node* tail) {
    if (tail == nullptr) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    cout << "\nDaftar Item (dari belakang):" << endl;
    node* temp = tail;
    int nomor = 1;
    while (temp != nullptr) {
        cout << nomor << ". nama_item: " << temp->item.nama_item
             << ", jumlah: " << temp->item.jumlah
             << ", tipe: " << temp->item.tipe << endl;
        temp = temp->prev;  
        nomor++;
    }
    cout << endl;
}

void seacrhitem(node* head, const string& namaCari) {
    if (isEmpty(head)) {
        cout << ">> Inventory kosong!" << endl;
        return;
    }

    node* temp = head;
    bool ditemukan = false;

    while (temp != nullptr) {
        if (temp->item.nama_item == namaCari) {
            cout << "\n--- DETAIL ITEM ---" << endl;
            cout << "Nama   : " << temp->item.nama_item << endl;
            cout << "Jumlah : " << temp->item.jumlah << endl;
            cout << "Tipe   : " << temp->item.tipe << endl;
            cout << "-------------------------------" << endl;
            ditemukan = true;
            break; 
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << ">> Item dengan nama '" << namaCari << "' tidak ditemukan" << endl;
    }
}

void menu(string nama, string nim) {
    node* head = nullptr;
    node* tail = nullptr; 
    int pilihan;
    int subPilihan;
    int pos;
    Item data;

    do {
        system("cls");
        cout << "\n=== GAME INVENTORY MANAGEMENT  ===" << endl;
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Tambah item" << endl;
        cout << "2. Hapus item" << endl;
        cout << "3. Ubah data item" << endl;
        cout << "4. Gunakan item" << endl;
        cout << "5. Tampilkan semua item" << endl;
        cout << "6. Tampilkan semua item dari belakang" << endl;
        cout << "7. Cari item berdasarkan nama" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

                switch (pilihan) {
            case 1:
                system("cls");
                cout << "\n--- Pilih Penambahan ---" << endl;
                cout << "1. Di Awal" << endl;
                cout << "2. Di Akhir" << endl;
                cout << "3. Di Posisi Tertentu" << endl;
                cout << "Pilih: ";
                cin >> subPilihan;
                cout << "----------------------------------" << endl;
                cout << "Masukkan nama item: ";
                cin >> data.nama_item;
                cout << "Masukkan jumlah: ";
                cin >> data.jumlah;
                cout << "Masukkan tipe (sword/potions/dll): ";
                cin >> data.tipe;
                cout << "----------------------------------" << endl;

                switch (subPilihan) {
                    case 1:
                        addFirst(head, tail, data);  
                        break;
                    case 2:
                        addLast(head, tail, data);   
                        break;
                    case 3:
                        cout << "Masukkan posisi: ";
                        cin >> pos;
                        addMiddle(head, tail, data, pos); 
                        break;
                    default:
                        cout << ">> Pilihan tidak valid!" << endl;
                        break;
                }
                break;

            case 2:
                system("cls");
                cout << "\n--- Pilih Penghapusan ---" << endl;
                cout << "1. Di Awal" << endl;
                cout << "2. Di Akhir" << endl;
                cout << "3. Di Posisi Tertentu" << endl;
                cout << "Pilih: ";
                cin >> subPilihan;
                cout << "----------------------------" << endl;

                switch (subPilihan) {
                    case 1:
                        deleteFirst(head, tail);  
                        break;
                    case 2:
                        deleteLast(head, tail); 
                        break;
                    case 3:
                        cout << "Masukkan posisi yang ingin dihapus: ";
                        cin >> pos;
                        deleteMiddle(head, tail, pos);
                        break;
                    default:
                        cout << ">> Pilihan tidak valid!" << endl;
                        break;
                }
                break;

            case 3:
                system("cls");
                cout << "----------------------------------" << endl;
                cout << "Masukkan posisi yang ingin diubah: ";
                cin >> pos;
                cout << "Masukkan nama item baru: ";
                cin >> data.nama_item;  
                cout << "Masukkan jumlah baru: ";
                cin >> data.jumlah;
                cout << "Masukkan tipe baru: ";
                cin >> data.tipe;
                editData(head, pos, data);
                cout << "----------------------------------" << endl;
                break;

            case 4:
                system("cls");
                useItem(head, tail); 
                break;

            case 5:
                system("cls");
                display(head); 
                break;

            case 6:
                system("cls");
                lihatbelakang(tail);
                break;

            case 7:
                system("cls");  
                {
                    string namaCari;
                    cout << "Masukkan nama item yang ingin dicari: ";
                    cin >> namaCari;
                    seacrhitem(head, namaCari); 
                }
                break;

            case 0:
                system("cls");
                cout << "Terima kasih telah menggunakan program ini" << endl;
                break;

            default:
                cout << ">> Pilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 0);
}

int main() {
    string nama, nim;

    cout << "=== PROGRAM INVENTORY GAME ===" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";   
    getline(cin, nim);
    cout << "----------------------------------" << endl;

    menu(nama, nim);

    return 0;
}