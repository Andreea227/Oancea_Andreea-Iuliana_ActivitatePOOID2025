#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class AparatElectrocasnic {
private:
    string denumire;
    int consumW;
    int nrFunctii;
    int* timpFunctii;

public:
    AparatElectrocasnic() {
        this->denumire = "";
        this->consumW = 0;
        this->nrFunctii = 0;
        this->timpFunctii = nullptr;
    }
    AparatElectrocasnic(string denumire, int consumW, int nrFunctii, int* timpFunctii) {
        this->denumire = denumire;
        this->consumW = consumW;
        this->nrFunctii = nrFunctii;

        this->timpFunctii = new int[nrFunctii];
        for (int i = 0; i < nrFunctii; i++) {
            this->timpFunctii[i] = timpFunctii[i];
        }
    }
    AparatElectrocasnic(const AparatElectrocasnic& a) {
        this->denumire = a.denumire;
        this->consumW = a.consumW;
        this->nrFunctii = a.nrFunctii;

        this->timpFunctii = new int[a.nrFunctii];
        for (int i = 0; i < a.nrFunctii; i++) {
            this->timpFunctii[i] = a.timpFunctii[i];
        }
    }
    ~AparatElectrocasnic() {
        if (this->timpFunctii != nullptr) {
            delete[] this->timpFunctii;
        }
    }
    int getConsumW() const {
        return this->consumW;
    }
    void setConsumW(int consumNou) {
        this->consumW = consumNou;
    }
};