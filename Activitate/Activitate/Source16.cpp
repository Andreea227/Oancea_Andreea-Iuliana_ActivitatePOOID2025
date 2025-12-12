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

    Magazin(const Magazin& m) {
        this->nume = m.nume;
        this->nrProduse = m.nrProduse;

        this->preturi = new float[m.nrProduse];
        for (int i = 0; i < m.nrProduse; i++) {
            this->preturi[i] = m.preturi[i];
        }
    }

    ~Magazin() {
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }
    }

    int getNrProduse() const {
        return this->nrProduse;
    }
};