#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Masina {
private:
    string marca;
    int anFabricatie;
    const int nrRoti;
    static int totalMasini;
    float* preturi;
    int nrPreturi;
public:
    string getMarca() const { 
        return marca; }
    int getAn() const { 
        return anFabricatie; }
    int getNrRoti() const {
        return nrRoti; }
    int getNrPreturi() const {
        return nrPreturi; }
    float getPret(int i) const {
        return (i >= 0 && i < nrPreturi) ? preturi[i] : 0;
    }

    void setMarca(string m) {
        marca = m; }
    void setAn(int a) {
        anFabricatie = a; }

    Masina() : nrRoti(4) {
        marca = "Necunoscut";
        anFabricatie = 0;
        nrPreturi = 0;
        preturi = nullptr;
        totalMasini++;
    }
    Masina(string marca, int an) : nrRoti(4) {
        this->marca = marca;
        this->anFabricatie = an;
        nrPreturi = 0;
        preturi = nullptr;
        totalMasini++;
    }
    Masina(string marca, int an, int nrPreturi, float* preturi) : nrRoti(4) {
        this->marca = marca;
        anFabricatie = an;
        this->nrPreturi = nrPreturi;
        this->preturi = new float[nrPreturi];
        for (int i = 0; i < nrPreturi; i++)
            this->preturi[i] = preturi[i];
        totalMasini++;
    }
};
