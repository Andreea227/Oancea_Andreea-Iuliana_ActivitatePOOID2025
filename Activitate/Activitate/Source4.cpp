#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class AparatAudio {
private:
    string marca;
    int putereW;
    int nrModele;
    int* aniModele;
public:
    AparatAudio() {
        this->marca = "";
        this->putereW = 0;
        this->nrModele = 0;
        this->aniModele = nullptr;
    }
    AparatAudio(string marca, int putereW, int nrModele, int* aniModele) {
        this->marca = marca;
        this->putereW = putereW;
        this->nrModele = nrModele;

        this->aniModele = new int[nrModele];
        for (int i = 0; i < nrModele; i++) {
            this->aniModele[i] = aniModele[i];
        }
    }

};
