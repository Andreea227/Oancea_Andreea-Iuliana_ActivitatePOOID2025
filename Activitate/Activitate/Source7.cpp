#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Instalatie {
private:
    string tip;
    int nrComponente;
    int capacitate;
    int* componente;
public:
    Instalatie() {
        tip = "";
        nrComponente = 0;
        capacitate = 0;
        componente = nullptr;
    }
    Instalatie(string tip, int nrComponente, int capacitate, int* comp) {
        this->tip = tip;
        this->nrComponente = nrComponente;
        this->capacitate = capacitate;
        this->componente = new int[nrComponente];
        for (int i = 0; i < nrComponente; i++)
            this->componente[i] = comp[i];
    }
};