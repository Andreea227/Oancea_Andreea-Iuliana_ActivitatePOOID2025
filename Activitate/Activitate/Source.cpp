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
int Motor::totalMotoare = 0;
class ServiceAuto {
public:
    string nume;
    int nrMecanici;
    static int totalServiceuri;
    const int anDeschidere;
    int* salarii;
    int nrSalarii;

    ServiceAuto() : anDeschidere(2000) {
        nume = "Necunoscut";
        nrMecanici = 0;
        nrSalarii = 0;
        salarii = nullptr;
        totalServiceuri++;
    }
    ServiceAuto(string nume, int nrMec) : anDeschidere(2000) {
        this->nume = nume;
        nrMecanici = nrMec;
        nrSalarii = 0;
        salarii = nullptr;
        totalServiceuri++;
    }
    ServiceAuto(string nume, int nrMec, int nrSalarii, int* salarii) : anDeschidere(2000) {
        this->nume = nume;
        this->nrMecanici = nrMec;
        this->nrSalarii = nrSalarii;

        this->salarii = new int[nrSalarii];
        for (int i = 0; i < nrSalarii; i++)
            this->salarii[i] = salarii[i];

        totalServiceuri++;
    }
    ~ServiceAuto() {
        delete[] salarii;
    }
    static void total() {
        cout << "Total service-uri create: " << totalServiceuri << endl;
    }
};
int ServiceAuto::totalServiceuri = 0;

int main() {
    float preturi[] = { 20000, 25000, 30000 };
    float rev[] = { 500, 700 };
    int salarii[] = { 3000, 3500, 4000 };
    Masina m1;
    Masina m2("BMW", 2018);
    Masina m3("Audi", 2020, 3, preturi);

    Masina::afisareTotal();
    Motor mo1;
    Motor mo2("Diesel", 2.0f);
    Motor mo3("Benzina", 1.6f, 2, rev);

    Motor::total();
    ServiceAuto s1;
    ServiceAuto s2("AutoFix", 5);
    ServiceAuto s3("PremiumService", 10, 3, salarii);

    ServiceAuto::total();
    return 0;
}