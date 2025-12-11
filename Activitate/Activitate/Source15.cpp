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

    MasinaElectrica(const MasinaElectrica& m) {
        this->model = m.model;
        this->pret = m.pret;
        this->autonomie = m.autonomie;
        this->nrAni = m.nrAni;

        this->incarcareAnuala = new int[m.nrAni];
        for (int i = 0; i < m.nrAni; i++) {
            this->incarcareAnuala[i] = m.incarcareAnuala[i];
        }
    }

    ~MasinaElectrica() {
        if (this->incarcareAnuala != nullptr) {
            delete[] this->incarcareAnuala;
        }
    }

    int getAutonomie() const {
        return this->autonomie;
    }

    void setAutonomie(int a) {
        this->autonomie = a;
    }

    MasinaElectrica operator+(const MasinaElectrica& m) const {
        MasinaElectrica rez = *this;
        rez.autonomie = this->autonomie + m.autonomie;
        return rez;
    }
};