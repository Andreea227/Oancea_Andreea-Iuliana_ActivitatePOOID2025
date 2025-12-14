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
    Apartament(string adresa, float pret, int nrCamere, float* suprafete) {
        this->adresa = adresa;
        this->pret = pret;
        this->nrCamere = nrCamere;

        this->suprafete = new float[nrCamere];
        for (int i = 0; i < nrCamere; i++) {
            this->suprafete[i] = suprafete[i];
        }
    }
    Apartament(const Apartament& a) {
        this->adresa = a.adresa;
        this->pret = a.pret;
        this->nrCamere = a.nrCamere;

        this->suprafete = new float[a.nrCamere];
        for (int i = 0; i < a.nrCamere; i++) {
            this->suprafete[i] = a.suprafete[i];
        }
    }
    Apartament& operator=(const Apartament& a) {
        if (this != &a) {
            this->adresa = a.adresa;
            this->pret = a.pret;
            this->nrCamere = a.nrCamere;

            delete[] this->suprafete;
            this->suprafete = new float[a.nrCamere];
            for (int i = 0; i < a.nrCamere; i++) {
                this->suprafete[i] = a.suprafete[i];
            }
        }
        return *this;
    }
};