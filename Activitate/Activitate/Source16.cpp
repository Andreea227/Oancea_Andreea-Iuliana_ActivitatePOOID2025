#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Magazin {
private:
    string nume;
    int nrProduse;
    float* preturi;
public:
    Magazin() {
        this->nume = "";
        this->nrProduse = 0;
        this->preturi = nullptr;
    }

    Magazin(string nume, int nrProduse, float* preturi) {
        this->nume = nume;
        this->nrProduse = nrProduse;

        this->preturi = new float[nrProduse];
        for (int i = 0; i < nrProduse; i++) {
            this->preturi[i] = preturi[i];
        }
    }
};