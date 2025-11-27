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
public:
    string getNume() const {
        return nume; }
    int getNrMecanici() const { 
        return nrMecanici; }
    int getAnDeschidere() const {
        return anDeschidere;
    }
    void setNume(string n) {
        nume = n; }
    void setNrMecanici(int x) {
        nrMecanici = x; 
    }
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
    ServiceAuto(string n, int m, int ns, int* sal) : anDeschidere(2000) {
        nume = n;
        nrMecanici = m;
        nrSalarii = ns;

        salarii = new int[nrSalarii];
        for (int i = 0; i < nrSalarii; i++)
            salarii[i] = sal[i];

        totalServiceuri++;
    }
    ServiceAuto(const ServiceAuto& s) : anDeschidere(2000) {
        nume = s.nume;
        nrMecanici = s.nrMecanici;
        nrSalarii = s.nrSalarii;

        if (s.salarii != nullptr) {
            salarii = new int[nrSalarii];
            for (int i = 0; i < nrSalarii; i++)
                salarii[i] = s.salarii[i];
        }
        else {
            salarii = nullptr;
        }

        totalServiceuri++;
    }
    ~ServiceAuto() {
        delete[] salarii;
    }
    static int getTotalServiceuri() { return totalServiceuri; }

    static void total() {
        cout << "Total service-uri create: " << totalServiceuri << endl;
    }
};
int ServiceAuto::totalServiceuri = 0;

float pretMediuMasina(const Masina& m) {
    if (m.nrPreturi == 0) return 0;
    float s = 0;
    for (int i = 0; i < m.nrPreturi; i++)
        s += m.preturi[i];
    return s / m.nrPreturi;
}
float sumaRevizii(const Motor& m) {
    float s = 0;
    for (int i = 0; i < m.nrRevizii; i++)
        s += m.revizii[i];
    return s;
}
int main() {
        float preturi[] = { 20000, 25000, 30000 };
        float rev[] = { 500, 700 };
        int salarii[] = { 3000, 3500, 4000 };

        Masina m1;
        Masina m2("BMW", 2018);
        Masina m3("Audi", 2020, 3, preturi);

        cout << "Pret mediu masina m3: " << pretMediuMasina(m3) << endl;
        Masina::afisareTotal();

        Motor mo1;
        Motor mo2("Diesel", 2.0f);
        Motor mo3("Benzina", 1.6f, 2, rev);

        cout << "Suma revizii mo3: " << sumaRevizii(mo3) << endl;
        Motor::total();

        ServiceAuto s1;
        ServiceAuto s2("AutoFix", 5);
        ServiceAuto s3("PremiumService", 10, 3, salarii);

        ServiceAuto::total();
}