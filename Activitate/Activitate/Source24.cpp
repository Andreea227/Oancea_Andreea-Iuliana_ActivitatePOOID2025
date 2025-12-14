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
    ~Apartament() {
        delete[] this->suprafete;
    }
    Apartament operator+(float valoare) const {
        Apartament aux = *this;
        aux.pret += valoare;
        return aux;
    }
    bool operator>(const Apartament& a) const {
        return this->pret > a.pret;
    }
    friend ostream& operator<<(ostream& out, const Apartament& a) {
        out << "Adresa: " << a.adresa << endl;
        out << "Pret: " << a.pret << endl;
        out << "Camere: " << a.nrCamere << endl;
        return out;
    }
};

int main() {
    float sup[] = { 20.5, 18.3 };
    Apartament a1("Str. Unirii", 120000, 2, sup);

    Apartament a2 = a1 + 10000;

    if (a2 > a1) {
        cout << "a2 este mai scump." << endl;
    }

    cout << a2 << endl;
}