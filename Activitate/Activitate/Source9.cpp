#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Oala {
private:
    string material;
    int capacitate; 
    int nrManere;
    int* diametre; 
public:
    Oala() {
        material = "";
        capacitate = 0;
        nrManere = 0;
        diametre = nullptr;
    }
    Oala(string material, int capacitate, int nrManere, int* diametre) {
        this->material = material;
        this->capacitate = capacitate;
        this->nrManere = nrManere;
        this->diametre = new int[nrManere];
        for (int i = 0; i < nrManere; i++)
            this->diametre[i] = diametre[i];
    }
    Oala(const Oala& o) {
        material = o.material;
        capacitate = o.capacitate;
        nrManere = o.nrManere;
        diametre = new int[o.nrManere];
        for (int i = 0; i < o.nrManere; i++)
            diametre[i] = o.diametre[i];
    }
};