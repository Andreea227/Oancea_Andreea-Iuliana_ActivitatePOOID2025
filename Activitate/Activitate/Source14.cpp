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
};