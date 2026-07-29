#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

string antrean[MAX];
int depan = 0;
int belakang = -1;
int jumlah = 0;

bool isEmpty() {
    return jumlah == 0;
}

bool isFull() {
    return jumlah == MAX;
}

void enqueue() {
    if (isFull()) {
        cout << "Antrean penuh!\n";
        return;
    }

    string nama;
    cin.ignore();
    cout << "Masukkan nama pengunjung : ";
    getline(cin, nama);

    belakang++;
    antrean[belakang] = nama;
    jumlah++;

    cout << nama << " berhasil mengambil nomor antrean.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrean kosong!\n";
        return;
    }

    cout << antrean[depan] << " dipanggil ke loket.\n";

    for (int i = depan; i < belakang; i++) {
        antrean[i] = antrean[i + 1];
    }

    belakang--;
    jumlah--;
}

void peek() {
    if (isEmpty()) {
        cout << "Antrean kosong!\n";
    } else {
        cout << "Antrean terdepan : " << antrean[depan] << endl;
    }
}

void size() {
    cout << "Jumlah antrean : " << jumlah << endl;
}

void tampilSemua() {
    if (isEmpty()) {
        cout << "Antrean kosong!\n";
        return;
    }

    cout << "Daftar Antrean:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". " << antrean[i] << endl;
    }
}

void cekKosong() {
    if (isEmpty())
        cout << "Antrean kosong.\n";
    else
        cout << "Antrean tidak kosong.\n";
}

void cekPenuh() {
    if (isFull())
        cout << "Antrean penuh.\n";
    else
        cout << "Antrean belum penuh.\n";
}

void menu() {
    cout << "=== SISTEM ANTREAN LOKET PELAYANAN ===\n";
    cout << "1. Ambil Antrean (Enqueue)\n";
    cout << "2. Panggil Antrean (Dequeue)\n";
    cout << "3. Lihat Antrean Terdepan (Peek)\n";
    cout << "4. Jumlah Antrean (Size)\n";
    cout << "5. Tampilkan Semua Antrean\n";
    cout << "6. Cek Antrean Kosong\n";
    cout << "7. Cek Antrean Penuh\n";
    cout << "0. Keluar\n";
}

int main() {
    int pilih;

    menu(); // Menu hanya tampil sekali

    do {
        cout << "\nPilihan : ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            size();
            break;

        case 5:
            tampilSemua();
            break;

        case 6:
            cekKosong();
            break;

        case 7:
            cekPenuh();
            break;

        case 0:
            cout << "Terima kasih.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    return 0;
}
