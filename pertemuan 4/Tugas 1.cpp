#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama, nim, kelas;

public:
    // Setter
    void setNama(string n) { nama = n; }
    void setNim(string n) { nim = n; }
    void setKelas(string k) { kelas = k; }

    // Getter
    string getNama() { return nama; }
    string getNim() { return nim; }
    string getKelas() { return kelas; }
};

int main() {
    Mahasiswa m;
    string n, i, k;

    cout << "=== INPUT DATA ===\n";
    cout << "Nama     : "; getline(cin, n);
    cout << "NIM      : "; getline(cin, i);
    cout << "Kelas    : "; getline(cin, k);

    m.setNama(n);
    m.setNim(i);
    m.setKelas(k);

    cout << "\n------------------------\n";
    cout << "   DATA MAHASISWA\n";
    cout << "------------------------\n";
    cout << "Nama     : " << m.getNama() << endl;
    cout << "NIM      : " << m.getNim() << endl;
    cout << "Kelas    : " << m.getKelas() << endl;
    cout << "------------------------\n";

    return 0;
}
