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

    friend ostream& operator<<(ostream& out, const MasinaElectrica& m) {
        out << "Model: " << m.model << endl;
        out << "Pret: " << m.pret << " euro" << endl;
        out << "Autonomie: " << m.autonomie << " km" << endl;
        out << "Ani utilizare: " << m.nrAni << endl;

        for (int i = 0; i < m.nrAni; i++) {
            out << "  Incarcari anul " << i + 1 << ": " << m.incarcareAnuala[i] << endl;
        }

        return out;
    }
};

int main() {
    int incarcare1[] = { 50, 60, 55 };
    int incarcare2[] = { 40, 45, 50 };
    MasinaElectrica m1;
    MasinaElectrica m2("Tesla Model 3", 45000, 450, 3, incarcare1);
    MasinaElectrica m3("Renault Zoe", 30000, 300, 3, incarcare2);
    cout << m2 << endl;
    cout << m3 << endl;
    MasinaElectrica m4 = m2 + m3;
}