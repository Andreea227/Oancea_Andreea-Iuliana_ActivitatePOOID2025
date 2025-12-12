#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Magazin {
private:
    string nume;
    int nrProduse;
    float* preturi;
public:
    Magazin() {
        this->nume = "";
        this->nrProduse = 0;
        this->preturi = nullptr;
    }
};