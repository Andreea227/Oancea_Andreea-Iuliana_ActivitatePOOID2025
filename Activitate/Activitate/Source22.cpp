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

    DispozitivElectronic(string denumire, float pret, int nrModule, int* module) {
        this->denumire = denumire;
        this->pret = pret;
        this->nrModule = nrModule;

        this->module = new int[nrModule];
        for (int i = 0; i < nrModule; i++) {
            this->module[i] = module[i];
        }
    }
};