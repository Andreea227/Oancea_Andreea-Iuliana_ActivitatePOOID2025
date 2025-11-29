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
};
