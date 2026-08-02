#include <iostream>
#include <string>
using namespace std;

enum Status {
    EMPTY,
    FILLED,
    DELETED
};

struct Item {
    string nama;
    int key;
    Status status;

    Item() {
        nama = "";
        key = 0;
        status = EMPTY;
    }
};

Item *hashTable;
int SIZE;

bool isPrima(int n) {
    if(n <= 1)
        return false;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int nextPrima(int n) {
    while(!isPrima(n))
        n++;

    return n;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insertItem() {
    string nama;
    int key;

    cout << "\Masukkan nama item : ";
    cin >> nama;

    cout << "Masukkan key item : ";
    cin >> key;

    int index = hashFunction(key);
    int awal = index;

    while(hashTable[index].status == FILLED) {
        index = (index + 1) % SIZE;

        if(index == awal) {
            cout << "Hash Table penuh!\n";
            return;
        }
    }

    hashTable[index].nama = nama;
    hashTable[index].key = key;
    hashTable[index].status = FILLED;

    cout << "Item berhasil disimpan pada index "
         << index << endl;
}

void hapusItem() {
    int key;

    cout << "\nMasukkan key yang ingin dihapus : ";
    cin >> key;

    int index = hashFunction(key);
    int awal = index;

    while(hashTable[index].status != EMPTY) {

        if(hashTable[index].status == FILLED &&
           hashTable[index].key == key) {

            hashTable[index].status = DELETED;
            cout << "Item berhasil dihapus.\n";
            return;
        }

        index = (index + 1) % SIZE;

        if(index == awal)
            break;
    }

    cout << "Item tidak ditemukan.\n";
}

void lihatItem() {
    int key;

    cout << "\Masukkan key yang dicari : ";
    cin >> key;

    int index = hashFunction(key);
    int awal = index;

    while(hashTable[index].status != EMPTY) {

        if(hashTable[index].status == FILLED &&
           hashTable[index].key == key) {

            cout << "\nData ditemukan\n";
            cout << "Index : " << index << endl;
            cout << "Nama  : " << hashTable[index].nama << endl;
            cout << "Key   : " << hashTable[index].key << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if(index == awal)
            break;
    }

    cout << "Data tidak ditemukan.\n";
}

void tampilkanSemua() {
    cout << "\Semua Data Inventory\n";

    bool ada = false;

    for(int i = 0; i < SIZE; i++) {

        if(hashTable[i].status == FILLED) {

            cout << "\nIndex : " << i << endl;
            cout << "Nama  : " << hashTable[i].nama << endl;
            cout << "Key   : " << hashTable[i].key << endl;
            cout << "----------------------\n";

            ada = true;
        }
    }

    if(!ada)
        cout << "Data masih kosong.\n";
}

int main() {
    int jumlahData;

    cout << "Masukkan jumlah data : ";
    cin >> jumlahData;

    if(!isPrima(jumlahData)) {
        SIZE = nextPrima(jumlahData);
        cout << "Ukuran Hash Table diubah menjadi "
             << SIZE << endl;
    }
    else {
        SIZE = jumlahData;
    }

    hashTable = new Item[SIZE];

    int pilihan;

    do {
        cout << "\nInventory Manajemen Sederhana\n";
        cout << "1. Insert Item\n";
        cout << "2. Hapus Item\n";
        cout << "3. Cari/Lihat Item\n";
        cout << "4. Tampilkan Semua Item\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                insertItem();
                break;
            case 2:
                hapusItem();
                break;
            case 3:
                lihatItem();
                break;
            case 4:
                tampilkanSemua();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }

    } while(pilihan != 0);

    delete[] hashTable;

    return 0;
}
