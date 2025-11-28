#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class AparatElectrocasnic {
private:
    string denumire;
    int consumW;
    int nrFunctii;
    int* timpFunctii;

public:
    AparatElectrocasnic() {
        this->denumire = "";
        this->consumW = 0;
        this->nrFunctii = 0;
        this->timpFunctii = nullptr;
    }
};