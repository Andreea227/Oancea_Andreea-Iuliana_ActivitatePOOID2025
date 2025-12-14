#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class VehiculElectric {
private:
    string model;
    float pret;
    int nrBaterii;
    int* capacitati;
public:
    VehiculElectric() {
        this->model = "";
        this->pret = 0;
        this->nrBaterii = 0;
        this->capacitati = nullptr;
    }
    VehiculElectric(string model, float pret, int nrBaterii, int* capacitati) {
        this->model = model;
        this->pret = pret;
        this->nrBaterii = nrBaterii;

        this->capacitati = new int[nrBaterii];
        for (int i = 0; i < nrBaterii; i++) {
            this->capacitati[i] = capacitati[i];
        }
    }
    VehiculElectric(const VehiculElectric& v) {
        this->model = v.model;
        this->pret = v.pret;
        this->nrBaterii = v.nrBaterii;

        this->capacitati = new int[v.nrBaterii];
        for (int i = 0; i < v.nrBaterii; i++) {
            this->capacitati[i] = v.capacitati[i];
        }
    }
    VehiculElectric& operator=(const VehiculElectric& v) {
        if (this != &v) {
            this->model = v.model;
            this->pret = v.pret;
            this->nrBaterii = v.nrBaterii;

            delete[] this->capacitati;
            this->capacitati = new int[v.nrBaterii];
            for (int i = 0; i < v.nrBaterii; i++) {
                this->capacitati[i] = v.capacitati[i];
            }
        }
        return *this;
    }
    ~VehiculElectric() {
        delete[] this->capacitati;
    }
    float getPret() const {
        return this->pret;
    }
    void setPret(float pret) {
        this->pret = pret;
    }

};