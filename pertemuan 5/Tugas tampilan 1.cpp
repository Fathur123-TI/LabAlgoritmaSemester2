#include <iostream>
using namespace std;

// class untuk menyimpan dan menampilkan sebuah nilai
class contoh {
private:
    int nilai; // variabel private, hanya bisa diakses di dalam class

public:
    // constructor
    // constructor adalah fungsi khusus yang otomatis dipanggil
    // saat sebuah objek dibuat
    // fungsi ini digunakan untuk memberi nilai awal pada variabel
    contoh(int n) {
        nilai = n; // nilai dari parameter n disimpan ke variabel nilai
    }

    // fungsi getNum()
    // fungsi ini digunakan untuk mengambil atau mengembalikan
    // isi dari variabel nilai
    int getNum() {
        return nilai;
    }
};

int main() {
    // membuat objek bernama obj dari class contoh
    // angka 10 dikirim ke constructor
    // lalu constructor akan menyimpan 10 ke variabel nilai
    contoh obj(10);

    // menampilkan teks dan nilai yang tersimpan di dalam objek
    // obj.getNum() dipakai untuk mengambil nilai dari objek
    cout << "nilai yang diinput: " << obj.getNum() << endl;

    return 0; // menandakan program selesai dengan baik
}
