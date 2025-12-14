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
};