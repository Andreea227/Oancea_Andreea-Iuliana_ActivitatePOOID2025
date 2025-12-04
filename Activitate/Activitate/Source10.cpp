#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class InstalatieIndustriala {
private:
    string tip;
    int capacitate;
    int nrComponente;
    int* componente;
public:
    InstalatieIndustriala() {
        this->tip = "";
        this->capacitate = 0;
        this->componente = 0;
        this->componente = nullptr;
    }
    InstalatieIndustriala(string tip, int capacitate, int nrComponente, int* componente) {
        this->tip = tip;
        this->capacitate = capacitate;
        this->nrComponente = nrComponente;
        this->componente = new int[nrComponente];
        for (int i = 0; i < nrComponente; i++) {
            this->componente[i] = componente[i];
        }
    }
    InstalatieIndustriala(const InstalatieIndustriala& i) {
        this->tip = i.tip;
        this->capacitate = i.capacitate;
        this->nrComponente = i.nrComponente;
        this->componente = new int[i.nrComponente];
        for (int j = 0; j < i.nrComponente; j++) {
            this->componente[j] = i.componente[j];
        }
    }
    ~InstalatieIndustriala() {
        if (this->componente != nullptr) {
            delete[] this->componente;
        }
    }

};