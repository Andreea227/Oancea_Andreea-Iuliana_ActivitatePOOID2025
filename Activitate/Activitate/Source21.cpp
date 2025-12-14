#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class ProdusSportiv {
private:
    string denumire;
    float pret;
    int nrMarimi;
    int* marimi;
public:
    ProdusSportiv() {
        this->denumire = "";
        this->pret = 0;
        this->nrMarimi = 0;
        this->marimi = nullptr;
    }

    ProdusSportiv(string denumire, float pret, int nrMarimi, int* marimi) {
        this->denumire = denumire;
        this->pret = pret;
        this->nrMarimi = nrMarimi;

        this->marimi = new int[nrMarimi];
        for (int i = 0; i < nrMarimi; i++) {
            this->marimi[i] = marimi[i];
        }
    }

    ProdusSportiv(string denumire, float pret, int nrMarimi, int* marimi) {
        this->denumire = denumire;
        this->pret = pret;
        this->nrMarimi = nrMarimi;

        this->marimi = new int[nrMarimi];
        for (int i = 0; i < nrMarimi; i++) {
            this->marimi[i] = marimi[i];
        }
    }

    ~ProdusSportiv() {
        if (this->marimi != nullptr) {
            delete[] this->marimi;
        }
    }

    float getPret() const {
        return this->pret;
    }

    void setPret(float pret) {
        this->pret = pret;
    }


    bool operator!=(const ProdusSportiv& p) const {
        return (this->denumire != p.denumire || this->pret != p.pret);
    }


    friend ostream& operator<<(ostream& out, const ProdusSportiv& p) {
        out << "Produs sportiv: " << p.denumire << endl;
        out << "Pret: " << p.pret << " lei" << endl;
        out << "Numar marimi: " << p.nrMarimi << endl;

        for (int i = 0; i < p.nrMarimi; i++) {
            out << "  Marime " << i + 1 << ": " << p.marimi[i] << endl;
        }

        return out;
    }
};

int main() {
    int marimi[] = { 36, 38, 40 };

    ProdusSportiv p1;
    ProdusSportiv p2("Pantaloni sport", 180.0, 3, marimi);

    cout << p2 << endl;
}