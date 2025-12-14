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
    Colectie(const Colectie& c) {
        this->nume = c.nume;
        this->nrElemente = c.nrElemente;

        this->elemente = new int[c.nrElemente];
        for (int i = 0; i < c.nrElemente; i++) {
            this->elemente[i] = c.elemente[i];
        }
    }
    Colectie& operator=(const Colectie& c) {
        if (this != &c) {
            this->nume = c.nume;
            this->nrElemente = c.nrElemente;

            delete[] this->elemente;
            this->elemente = new int[c.nrElemente];
            for (int i = 0; i < c.nrElemente; i++) {
                this->elemente[i] = c.elemente[i];
            }
        }
        return *this;
    }

    ~Colectie() {
        delete[] this->elemente;
    }

    string getNume() const {
        return this->nume;
    }

    void setNume(string nume) {
        this->nume = nume;
    }

    int getNrElemente() const {
        return this->nrElemente;
    }

    int operator[](int index) const {
        if (index >= 0 && index < this->nrElemente) {
            return this->elemente[index];
        }
        return -1;
    }

    bool operator==(const Colectie& c) const {
        return (this->nrElemente == c.nrElemente);
    }
};