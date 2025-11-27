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
};
