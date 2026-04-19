#include <iostream>
#include <string>

using namespace std;

class Pelajaran {
	public:
		Pelajaran () {
			cout << "Ini adalah materi c++ tentang Constructors!" << endl;
		}		
}; 

int main () {
	Pelajaran obj;
	
	return 0;
}
