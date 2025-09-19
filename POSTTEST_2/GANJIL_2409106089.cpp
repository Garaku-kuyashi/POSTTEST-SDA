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
};

bool isEmpty(node* head) {
    return head == nullptr;
}

void addFirst(node*& head, const Item& data) {
    node* nodeBaru = new node;
    nodeBaru->item = data;
    nodeBaru->next = head;
    head = nodeBaru;
    cout << "Item ditambahkan di awal." << endl;
}

void addLast(node*& head, const Item& data) {
    node* nodeBaru = new node;
    nodeBaru->item = data;
    nodeBaru->next = nullptr;

    if (isEmpty(head)) {
        head = nodeBaru;
        cout << "Item ditambahkan sebagai yang pertama." << endl;
        return;
    }

    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    cout << "Item ditambahkan di akhir." << endl;
}

void addMiddle(node*& head, const Item& data, int posisi) {
    if (posisi <= 1) {
        addFirst(head, data);
        return;
    }

    node* temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr) {
        cout << ">> Posisi tidak valid" << endl;
        return;
    }

    node* nodeBaru = new node;
    nodeBaru->item = data;
    nodeBaru->next = temp->next;
    temp->next = nodeBaru;
    cout << "Item ditambahkan di posisi ke-" << posisi << "." << endl;
}

void deleteFirst(node*& head) {
    if (isEmpty(head)) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    node* temp = head;
    head = head->next;
    delete temp;
    cout << "Item pertama berhasil dihapus." << endl;
}

void deleteLast(node*& head) {
    if (isEmpty(head)) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Item terakhir berhasil dihapus." << endl;
        return;
    }

    node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    cout << "Item terakhir berhasil dihapus." << endl;
}

void deleteMiddle(node*& head, int posisi) {
    if (isEmpty(head)) {
        cout << ">> Daftar Item kosong!" << endl;
        return;
    }

    if (posisi <= 1) {
        deleteFirst(head);
        return;
    }

    node* temp = head;
    int hitung = 1;
    while (temp->next != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }

    if (temp->next == nullptr) {
        cout << ">> Posisi tidak valid!" << endl;
        return;
    }

    node* hapus = temp->next;
    temp->next = hapus->next;
    delete hapus;
    cout << "Item di posisi ke-" << posisi << " berhasil dihapus." << endl;
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
    cout << "nama_item: " << temp->item.nama_item << ", jumlah: " << temp->item.jumlah << ", tipe: " << temp->item.tipe << endl; // ✅ DIPERBAIKI

    temp->item = dataBaru;
    cout << "Data berhasil diubah!" << endl;
}

void useitem(node*& head) {
    if (isEmpty(head)) {
        cout << ">> Inventory kosong! Tidak ada item yang bisa digunakan." << endl;
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
            cout << "Item ditemukan!" << endl;
            cout << "Jumlah sebelum digunakan: " << temp->item.jumlah << endl;
            temp->item.jumlah--;

            if (temp->item.jumlah == 0) {
                cout << "Jumlah item habis. Item '" << namaCari << "' dihapus dari inventory." << endl;

                if (temp == head) {
                    head = head->next;
                    delete temp;
                } else {
                    node* prev = head;
                    while (prev->next != temp) {
                        prev = prev->next;
                    }
                    prev->next = temp->next;
                    delete temp;
                }
            } else {
                cout << "Item berhasil digunakan. Jumlah tersisa: " << temp->item.jumlah << endl;
            }
            break;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << ">> Item '" << namaCari << "' tidak ditemukan di inventory." << endl;
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
        cout << nomor << ". nama_item: " << temp->item.nama_item << ", jumlah: " << temp->item.jumlah << ", tipe: " << temp->item.tipe << endl; // ✅ DIPERBAIKI
        temp = temp->next;
        nomor++;
    }
    cout << endl;
}

void menu(string nama, string nim) {
    node* head = nullptr;
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
        cout << "1. Tambah Item" << endl;
        cout << "2. Hapus Item" << endl;
        cout << "3. Ubah Data Item" << endl;
        cout << "4. Gunakan Item" << endl;
        cout << "5. Tampilkan Semua Item" << endl;
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
                        addFirst(head, data);
                        break;
                    case 2:
                        addLast(head, data);
                        break;
                    case 3:
                        cout << "Masukkan posisi: ";
                        cin >> pos;
                        addMiddle(head, data, pos);
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
                        deleteFirst(head);
                        break;
                    case 2:
                        deleteLast(head);
                        break;
                    case 3:
                        cout << "Masukkan posisi yang ingin dihapus: ";
                        cin >> pos;
                        deleteMiddle(head, pos);
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
                useitem(head);
                break;

            case 5:
                system("cls");
                display(head);
                break;

            case 0:
                system("cls");
                cout << "Terima kasih telah menggunakan program ini!" << endl;
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