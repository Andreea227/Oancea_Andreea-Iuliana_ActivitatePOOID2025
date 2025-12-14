#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Apartament {
private:
    string adresa;
    float pret;
    int nrCamere;
    float* suprafete;
public:
    Apartament() {
        this->adresa = "";
        this->pret = 0;
        this->nrCamere = 0;
        this->suprafete = nullptr;
    }
};