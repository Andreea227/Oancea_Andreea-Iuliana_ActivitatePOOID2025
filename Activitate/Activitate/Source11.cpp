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
    Masina(string marca, int an, int nrPreturi, float* p) : nrRoti(4) {
        this->marca = marca;
        anFabricatie = an;
        this->nrPreturi = nrPreturi;

        preturi = new float[nrPreturi];
        for (int i = 0; i < nrPreturi; i++)
            preturi[i] = p[i];

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
        else preturi = nullptr;

        totalMasini++;
    }
    ~Masina() {
        delete[] preturi;
    }
    static void afisareTotal() {
        cout << "Total masini create: " << totalMasini << endl;
    }
    Masina& operator=(const Masina& m) {
        if (this == &m) return *this;

        marca = m.marca;
        anFabricatie = m.anFabricatie;

        delete[] preturi;

        nrPreturi = m.nrPreturi;
        if (m.preturi != nullptr) {
            preturi = new float[nrPreturi];
            for (int i = 0; i < nrPreturi; i++)
                preturi[i] = m.preturi[i];
        }
        else preturi = nullptr;

        return *this;
    }
    Masina operator+(int x) const {
        Masina temp(*this);
        temp.anFabricatie += x;
        return temp;
    }
    bool operator<(const Masina& m) const {
        return this->anFabricatie < m.anFabricatie;
    }
    float operator[](int index) const {
        if (index >= 0 && index < nrPreturi)
            return preturi[index];
        return 0;
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
    Motor() : nrCilindri(4) {
        tip = "Necunoscut";
        capacitate = 0;
        nrRevizii = 0;
        revizii = nullptr;
        totalMotoare++;
    }
    Motor(string t, float c) : nrCilindri(4) {
        tip = t;
        capacitate = c;
        nrRevizii = 0;
        revizii = nullptr;
        totalMotoare++;
    }
    Motor(string t, float c, int nr, float* r) : nrCilindri(4) {
        tip = t;
        capacitate = c;
        nrRevizii = nr;

        revizii = new float[nr];
        for (int i = 0; i < nr; i++)
            revizii[i] = r[i];

        totalMotoare++;
    }
    Motor(const Motor& m) : nrCilindri(4) {
        tip = m.tip;
        capacitate = m.capacitate;
        nrRevizii = m.nrRevizii;

        revizii = new float[nrRevizii];
        for (int i = 0; i < nrRevizii; i++)
            revizii[i] = m.revizii[i];

        totalMotoare++;
    }
    ~Motor() {
        delete[] revizii;
    }
    static void total() {
        cout << "Total motoare create: " << totalMotoare << endl;
    }
    Motor& operator=(const Motor& m) {
        if (this == &m) return *this;

        tip = m.tip;
        capacitate = m.capacitate;

        delete[] revizii;

        nrRevizii = m.nrRevizii;
        revizii = new float[nrRevizii];
        for (int i = 0; i < nrRevizii; i++)
            revizii[i] = m.revizii[i];

        return *this;
    }
    Motor operator+(float x) const {
        Motor temp(*this);
        temp.capacitate += x;
        return temp;
    }
    bool operator<(const Motor& m) const {
        return this->capacitate < m.capacitate;
    }
    float operator[](int index) const {
        if (index >= 0 && index < nrRevizii)
            return revizii[index];
        return 0;
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
public:
    ServiceAuto() : anDeschidere(2000) {
        nume = "Necunoscut";
        nrMecanici = 0;
        nrSalarii = 0;
        salarii = nullptr;
        totalServiceuri++;
    }
    ServiceAuto(string n, int m) : anDeschidere(2000) {
        nume = n;
        nrMecanici = m;
        nrSalarii = 0;
        salarii = nullptr;
        totalServiceuri++;
    }
    ServiceAuto(string n, int m, int ns, int* s) : anDeschidere(2000) {
        nume = n;
        nrMecanici = m;
        nrSalarii = ns;

        salarii = new int[nrSalarii];
        for (int i = 0; i < nrSalarii; i++)
            salarii[i] = s[i];

        totalServiceuri++;
    }
    ServiceAuto(const ServiceAuto& s) : anDeschidere(2000) {
        nume = s.nume;
        nrMecanici = s.nrMecanici;
        nrSalarii = s.nrSalarii;

        salarii = new int[nrSalarii];
        for (int i = 0; i < nrSalarii; i++)
            salarii[i] = s.salarii[i];

        totalServiceuri++;
    }
    ~ServiceAuto() {
        delete[] salarii;
    }
    static void total() {
        cout << "Total service-uri create: " << totalServiceuri << endl;
    }
    ServiceAuto& operator=(const ServiceAuto& s) {
        if (this == &s) return *this;

        nume = s.nume;
        nrMecanici = s.nrMecanici;

        delete[] salarii;

        nrSalarii = s.nrSalarii;

        salarii = new int[nrSalarii];
        for (int i = 0; i < nrSalarii; i++)
            salarii[i] = s.salarii[i];

        return *this;
    }
    ServiceAuto operator+(int x) const {
        ServiceAuto temp(*this);
        temp.nrMecanici += x;
        return temp;
    }
    bool operator<(const ServiceAuto& s) const {
        return this->nrMecanici < s.nrMecanici;
    }
};