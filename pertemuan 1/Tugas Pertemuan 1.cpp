#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah buku yang ingin di input : ";
    cin >> n;
    cin.ignore(); 
    
    string buku[n];


    for(int i = 0; i < n; i++) {
        cout << "judul buku ke-" << i+1 << ": ";
        getline(cin, buku[i]);
    }

    cout << "\nSebelum sorting:\n";
    for(int i = 0; i < n; i++) {
        cout << buku[i] << endl;
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(buku[j] > buku[j+1]) {
                swap(buku[j], buku[j+1]);
            }
        }
    }

    cout << "\nSetelah sorting:\n";
    for(int i = 0; i < n; i++) {
        cout << buku[i] << endl;
    }

    return 0;
}
