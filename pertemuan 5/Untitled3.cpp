#include <iostream>

using namespace std;

class Laptop {
	private:
		string pemilik;
		string merk;
		
	public:
		Laptop(string var1, string var2) {
			pemilik = var1;
			merk = var2;
			
			cout<< "Paket Laptop " << merk << " milik " << pemilik << " sudah dikirim" << endl;
	}
};

int main() {
	Laptop laptopFadlan("Fadlan", "Asus");
    Laptop laptopFathur("Fathur", "Acer");
    Laptop laptopFathir("Fathir", "Lenovo");
    
    return 0;
}
