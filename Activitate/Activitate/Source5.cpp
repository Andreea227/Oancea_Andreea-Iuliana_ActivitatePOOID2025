#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class AparatFoto {
private:
    string brand;
    int rezolutieMP;
    int nrModele;
    int* aniLansare;
public:
    AparatFoto() {
        this->brand = "";
        this->rezolutieMP = 0;
        this->nrModele = 0;
        this->aniLansare = nullptr;
    }
    AparatFoto(string brand, int rezolutieMP, int nrModele, int* ani) {
        this->brand = brand;
        this->rezolutieMP = rezolutieMP;
        this->nrModele = nrModele;

        this->aniLansare = new int[nrModele];
        for (int i = 0; i < nrModele; i++) {
            this->aniLansare[i] = ani[i];
        }
    }
    AparatFoto(const AparatFoto& af) {
        this->brand = af.brand;
        this->rezolutieMP = af.rezolutieMP;
        this->nrModele = af.nrModele;

        this->aniLansare = new int[af.nrModele];
        for (int i = 0; i < af.nrModele; i++) {
            this->aniLansare[i] = af.aniLansare[i];
        }
    }
    ~AparatFoto() {
        if (this->aniLansare != nullptr)
            delete[] this->aniLansare;
    }
    int getRezolutie() const {
        return this->rezolutieMP;
    }
};
