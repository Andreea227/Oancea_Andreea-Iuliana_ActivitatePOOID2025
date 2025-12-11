#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class MasinaElectrica {
private:
    string model;
    float pret;
    int autonomie;
    int nrAni;
    int* incarcareAnuala;
public:
    MasinaElectrica() {
        this->model = "";
        this->pret = 0;
        this->autonomie = 0;
        this->nrAni = 0;
        this->incarcareAnuala = nullptr;
    }
};