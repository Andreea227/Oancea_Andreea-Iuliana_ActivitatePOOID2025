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
    Masina(const Masina& m) : nrRoti(4) {
        marca = m.marca;
        anFabricatie = m.anFabricatie;
        nrPreturi = m.nrPreturi;

        if (m.preturi != nullptr) {
            preturi = new float[nrPreturi];
            for (int i = 0; i < nrPreturi; i++)
                preturi[i] = m.preturi[i];
        }
        else {
            preturi = nullptr;
        }

        totalMasini++;
    }
    ~Masina() {
        delete[] preturi;
    }
    static int getTotalMasini() { return totalMasini; }

    static void afisareTotal() {
        cout << "Total masini create: " << totalMasini << endl;
    }
    friend float pretMediuMasina(const Masina&);
    
};
int Masina::totalMasini = 0;
class Motor {
private:
    string tip;
    float capacitate;
    static int totalMotoare;
    const int nrCilindri;
    float* revizii;
    int nrRevizii;

public:
    string getTip() const {
        return tip; }
    float getCapacitate() const { 
        return capacitate; }
    int getNrCilindri() const {
        return nrCilindri;
    }
    void setTip(string t) {
        tip = t; }
    void setCapacitate(float c) {
        capacitate = c; 
    }
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
    Motor(string tip, float capacitate, int nrRevizii, float* rev) : nrCilindri(4) {
        this->tip = tip;
        this->capacitate = capacitate;
        this->nrRevizii = nrRevizii;

        revizii = new float[nrRevizii];
        for (int i = 0; i < nrRevizii; i++)
            revizii[i] = rev[i];

        totalMotoare++;
    }
    Motor(const Motor& m) : nrCilindri(4) {
        tip = m.tip;
        capacitate = m.capacitate;
        nrRevizii = m.nrRevizii;

        if (m.revizii != nullptr) {
            revizii = new float[nrRevizii];
            for (int i = 0; i < nrRevizii; i++)
                revizii[i] = m.revizii[i];
        }
        else {
            revizii = nullptr;
        }

        totalMotoare++;
    }
    ~Motor() {
        delete[] revizii;
    }
    static int getTotalMotoare() { return totalMotoare; }

    static void total() {
        cout << "Total motoare create: " << totalMotoare << endl;
    }
    friend float sumaRevizii(const Motor&);
};
int Motor::totalMotoare = 0;
class ServiceAuto {
private:
    string nume;
    int nrMecanici;
    static int totalServiceuri;
    const int anDeschidere;
    int* salarii;
    int nrSalarii;
};