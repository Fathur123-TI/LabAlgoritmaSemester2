#include <iostream>
#include <string>
using namespace std;

void gabung(string data[], int kiri, int tengah, int kanan) {
    string temp[100];
    int i = kiri, j = tengah + 1, k = 0;

    while (i <= tengah && j <= kanan) {
        if (data[i] < data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    while (i <= tengah) temp[k++] = data[i++];
    while (j <= kanan) temp[k++] = data[j++];

    for (int x = 0; x < k; x++) {
        data[kiri + x] = temp[x];
    }
}

void urutkan(string data[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        urutkan(data, kiri, tengah);
        urutkan(data, tengah + 1, kanan);
        gabung(data, kiri, tengah, kanan);
    }
}

int main() {
    string barang[] = {"Pallet", "Kardus", "Forklift", "Rak", "Meja", "Troli", "Helm"};
    int n = sizeof(barang) / sizeof(barang[0]);

    cout << "Data awal: ";
    for (int i = 0; i < n; i++) {
        cout << barang[i] << " ";
    }

    urutkan(barang, 0, n - 1);

    cout << "\nHasil setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << barang[i] << " ";
    }

    return 0;
}
