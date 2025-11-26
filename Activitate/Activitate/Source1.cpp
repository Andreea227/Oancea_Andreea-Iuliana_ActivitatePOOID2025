#define _CRT+_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Persoana {
private:
	string nume;
	int varsta;
public:
	Persoana(string nume, int varsta) {
		nume = nume;
		varsta = varsta;
	}

	string getNume()const {
		return nume;
	}
	 
	int getVarsta(int varsta) {
		varsta = varsta;
	}

	friend ostream& operator<<(ostream&out, const Persoana& p) {
		out << "Nume:" << p.nume << endl;
		out << "Varsta:" << p.varsta << endl;

	}
};