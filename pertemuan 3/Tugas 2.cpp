#include <iostream>
using namespace std;

int main() {
    string buku[] = {"Inggris", "Basis Data", "Matematika", "Pemrograman", "Phyton"};
    int n = 5;

    string cari;
    cout << "Cari buku: ";
    getline(cin, cari);

    int a = 0, b = n - 1;
    bool ada = false;

    while (a <= b) {
        int t = (a + b) / 2;

        if (buku[t] == cari) {
            cout << "Ketemu di rak ke- " << t + 1;
            ada = true;
            break;
        } else if (buku[t] < cari) {
            a = t + 1;
        } else {
            b = t - 1;
        }
    }

    if (!ada) cout << "Tidak ketemu";

    return 0;
}
