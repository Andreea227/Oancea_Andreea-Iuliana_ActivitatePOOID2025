#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class ProdusSportiv {
private:
    string denumire;
    float pret;
    int nrMarimi;
    int* marimi;
public:
    ProdusSportiv() {
        this->denumire = "";
        this->pret = 0;
        this->nrMarimi = 0;
        this->marimi = nullptr;
    }

    ProdusSportiv(string denumire, float pret, int nrMarimi, int* marimi) {
        this->denumire = denumire;
        this->pret = pret;
        this->nrMarimi = nrMarimi;

        this->marimi = new int[nrMarimi];
        for (int i = 0; i < nrMarimi; i++) {
            this->marimi[i] = marimi[i];
        }
    }

    ProdusSportiv(string denumire, float pret, int nrMarimi, int* marimi) {
        this->denumire = denumire;
        this->pret = pret;
        this->nrMarimi = nrMarimi;

        this->marimi = new int[nrMarimi];
        for (int i = 0; i < nrMarimi; i++) {
            this->marimi[i] = marimi[i];
        }
    }

    ~ProdusSportiv() {
        if (this->marimi != nullptr) {
            delete[] this->marimi;
        }
    }

    float getPret() const {
        return this->pret;
    }
};