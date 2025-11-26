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