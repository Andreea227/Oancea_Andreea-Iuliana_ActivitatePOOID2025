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
};
