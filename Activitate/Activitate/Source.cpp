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
};