#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Ornament {
private:
    string nume;
    float pret;
    int nrMateriale;
    string* materiale;
public:
    Ornament() {
        this->nume = "";
        this->pret = 0;
        this->nrMateriale = 0;
        this->materiale = nullptr;
    }
};