#include <iostream>
using namespace std;

int main() {
    int data[] = {0, 5, 15, 25, 35};
    int n = sizeof(data) / sizeof(data[0]);
    int cari;

    cout << "Masukkan data yang dicari: ";
    cin >> cari;

    int L = 0;
    int R = n - 1;
    bool ketemu = false;

    while (L <= R) {
        int mid = (L + R) / 2;

        if (data[mid] == cari) {
            cout << "Bilangan ditemukan";
            ketemu = true;
            break;
        } 
        else if (data[mid] < cari) {
            L = mid + 1;
        } 
        else {
            R = mid - 1;
        }
    }

    if (!ketemu) {
        cout << "Bilangan tidak ditemukan";
    }

    return 0;
}
