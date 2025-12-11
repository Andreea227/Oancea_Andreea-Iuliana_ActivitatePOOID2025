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

    MasinaElectrica(string model, float pret, int autonomie, int nrAni, int* incarcare) {
        this->model = model;
        this->pret = pret;
        this->autonomie = autonomie;
        this->nrAni = nrAni;

        this->incarcareAnuala = new int[nrAni];
        for (int i = 0; i < nrAni; i++) {
            this->incarcareAnuala[i] = incarcare[i];
        }
    }

};