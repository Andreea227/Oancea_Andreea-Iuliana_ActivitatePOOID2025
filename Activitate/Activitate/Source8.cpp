#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Imprimanta {
private:
    string model;
    int vitezaPagini;
    int nrCartuse;
    int* nivelCartuse;
public:
    Imprimanta() {
        model = "";
        vitezaPagini = 0;
        nrCartuse = 0;
        nivelCartuse = nullptr;
    }
    Imprimanta(string model, int vitezaPagini, int nrCartuse, int* nivelCartuse) {
        this->model = model;
        this->vitezaPagini = vitezaPagini;
        this->nrCartuse = nrCartuse;
        this->nivelCartuse = new int[nrCartuse];
        for (int i = 0; i < nrCartuse; i++)
            this->nivelCartuse[i] = nivelCartuse[i];
    }
    Imprimanta(const Imprimanta& i) {
        model = i.model;
        vitezaPagini = i.vitezaPagini;
        nrCartuse = i.nrCartuse;
        nivelCartuse = new int[i.nrCartuse];
        for (int j = 0; j < i.nrCartuse; j++)
            nivelCartuse[j] = i.nivelCartuse[j];
    }
    ~Imprimanta() {
        if (nivelCartuse != nullptr)
            delete[] nivelCartuse;
    }
};