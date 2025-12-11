#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class InstrumentMuzical {
private:
    string nume;
    float pret;
    int nrNote;
    int* frecvente;
public:
    InstrumentMuzical() {
        this->nume = "";
        this->pret = 0;
        this->nrNote = 0;
        this->frecvente = nullptr;
    }
    InstrumentMuzical(string nume, float pret, int nrNote, int* frecvente) {
        this->nume = nume;
        this->pret = pret;
        this->nrNote = nrNote;

        this->frecvente = new int[nrNote];
        for (int i = 0; i < nrNote; i++) {
            this->frecvente[i] = frecvente[i];
        }
    }
    InstrumentMuzical(const InstrumentMuzical& im) {
        this->nume = im.nume;
        this->pret = im.pret;
        this->nrNote = im.nrNote;

        this->frecvente = new int[im.nrNote];
        for (int i = 0; i < im.nrNote; i++) {
            this->frecvente[i] = im.frecvente[i];
        }
    }
    ~InstrumentMuzical() {
        if (this->frecvente != nullptr) {
            delete[] this->frecvente;
        }
    }
    float getPret() const {
        return this->pret;
    }
};