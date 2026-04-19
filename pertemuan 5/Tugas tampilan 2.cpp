#include <iostream>
using namespace std;

// class Mobil digunakan untuk merepresentasikan sebuah mobil
class Mobil {
private:
    string merk; // variabel untuk menyimpan merk mobil

public:
    // Constructor
    // fungsi ini otomatis dipanggil saat objek dibuat
    // digunakan untuk memberi nilai awal pada merk
    Mobil(string m) {
        merk = m;
        cout << "Mobil dibuat dengan merk: " << merk << endl;
    }

    // Destructor
    // fungsi ini otomatis dipanggil saat objek dihapus / program selesai
    ~Mobil() {
        cout << "Mobil dengan merk " << merk << " dihapus" << endl;
    }

    // fungsi untuk menjalankan aksi mobil
    void jalan() {
        cout << "Mobil " << merk << " sedang berjalan" << endl;
    }
};

int main() {
    // membuat objek m1 dari class Mobil
    // "Toyota" dikirim ke constructor lalu disimpan ke variabel merk
    Mobil m1("Toyota"); // constructor dipanggil

    // memanggil fungsi jalan()
    m1.jalan();

    return 0; // saat program selesai, destructor dipanggil otomatis
}
