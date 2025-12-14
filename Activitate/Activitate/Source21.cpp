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
};