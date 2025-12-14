#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class DispozitivElectronic {
private:
    string denumire;
    float pret;
    int nrModule;
    int* module;
public:
    DispozitivElectronic() {
        this->denumire = "";
        this->pret = 0;
        this->nrModule = 0;
        this->module = nullptr;
    }
};