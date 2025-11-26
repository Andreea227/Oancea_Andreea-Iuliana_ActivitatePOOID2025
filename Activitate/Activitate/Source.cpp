#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
 
using namespace std;
class Masina {
public:
    string marca;
    int anFabricatie;
    const int nrRoti;      
    static int totalMasini; 
    float* preturi;      
    int nrPreturi;

    Masina() : nrRoti(4) {
        marca = "Necunoscut";
        anFabricatie = 0;
        nrPreturi = 0;
        preturi = nullptr;
        totalMasini++;
    }

    Masina(string marca, int an) : nrRoti(4) {
        this->marca = marca;
        anFabricatie = an;
        nrPreturi = 0;
        preturi = nullptr;
        totalMasini++;
    }
    Masina(string marca, int an, int nrPreturi, float* preturi) : nrRoti(4) {
        this->marca = marca;
        this->anFabricatie = an;
        this->nrPreturi = nrPreturi;
        this->preturi = new float[nrPreturi];
        for (int i = 0; i < nrPreturi; i++)
            this->preturi[i] = preturi[i];

        totalMasini++;
    }
    ~Masina() {
        delete[] preturi;
    }
    static void afisareTotal() {
        cout << "Total masini create: " << totalMasini << endl;
    }
};
int Masina::totalMasini = 0;

class Motor {
public:
    string tip;
    float capacitate;
    static int totalMotoare;
    const int nrCilindri;
    float* revizii;
    int nrRevizii;

    Motor() : nrCilindri(4) {
        tip = "Necunoscut";
        capacitate = 0;
        nrRevizii = 0;
        revizii = nullptr;
        totalMotoare++;
    }
    Motor(string tip, float capacitate) : nrCilindri(4) {
        this->tip = tip;
        this->capacitate = capacitate;
        nrRevizii = 0;
        revizii = nullptr;
        totalMotoare++;
    }
    Motor(string tip, float capacitate, int nrRevizii, float* revizii) : nrCilindri(4) {
        this->tip = tip;
        this->capacitate = capacitate;
        this->nrRevizii = nrRevizii;

        this->revizii = new float[nrRevizii];
        for (int i = 0; i < nrRevizii; i++)
            this->revizii[i] = revizii[i];

        totalMotoare++;
    }
    ~Motor() {
        delete[] revizii;
    }
    static void total() {
        cout << "Total motoare create: " << totalMotoare << endl;
    }
};