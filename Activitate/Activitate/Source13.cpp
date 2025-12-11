#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Ornament {
private:
    string nume;
    float pret;
    int nrMateriale;
    string* materiale;
public:
    Ornament() {
        this->nume = "";
        this->pret = 0;
        this->nrMateriale = 0;
        this->materiale = nullptr;
    }
    Ornament(string nume, float pret, int nrMateriale, string* materiale) {
        this->nume = nume;
        this->pret = pret;
        this->nrMateriale = nrMateriale;

        this->materiale = new string[nrMateriale];
        for (int i = 0; i < nrMateriale; i++) {
            this->materiale[i] = materiale[i];
        }
    }
};