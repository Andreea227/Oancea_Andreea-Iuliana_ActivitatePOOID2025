#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Colectie {
private:
    string nume;
    int nrElemente;
    int* elemente;
public:
    Colectie() {
        this->nume = "";
        this->nrElemente = 0;
        this->elemente = nullptr;
    }
    Colectie(string nume, int nrElemente, int* elemente) {
        this->nume = nume;
        this->nrElemente = nrElemente;

        this->elemente = new int[nrElemente];
        for (int i = 0; i < nrElemente; i++) {
            this->elemente[i] = elemente[i];
        }
    }
};