#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class EchipamentSportiv {
private:
    string denumire;
    float pret;
    int nrMarimi;
    int* marimi;
public:
    EchipamentSportiv() {
        this->denumire = "";
        this->pret = 0;
        this->nrMarimi = 0;
        this->marimi = nullptr;
    }

    EchipamentSportiv(string denumire, float pret, int nrMarimi, int* marimi) {
        this->denumire = denumire;
        this->pret = pret;
        this->nrMarimi = nrMarimi;

        this->marimi = new int[nrMarimi];
        for (int i = 0; i < nrMarimi; i++) {
            this->marimi[i] = marimi[i];
        }
    }

    EchipamentSportiv(const EchipamentSportiv& e) {
        this->denumire = e.denumire;
        this->pret = e.pret;
        this->nrMarimi = e.nrMarimi;

        this->marimi = new int[e.nrMarimi];
        for (int i = 0; i < e.nrMarimi; i++) {
            this->marimi[i] = e.marimi[i];
        }
    }

    ~EchipamentSportiv() {
        if (this->marimi != nullptr) {
            delete[] this->marimi;
        }
    }

    float getPret() const {
        return this->pret;
    }

    void setPret(float p) {
        this->pret = p;
    }

    bool operator!=(const EchipamentSportiv& e) const {
        return (this->denumire != e.denumire || this->pret != e.pret);
    }

    friend ostream& operator<<(ostream& out, const EchipamentSportiv& e) {
        out << "Echipament: " << e.denumire << endl;
        out << "Pret: " << e.pret << " lei" << endl;
        out << "Numar marimi: " << e.nrMarimi << endl;

        for (int i = 0; i < e.nrMarimi; i++) {
            out << "  Marime " << i + 1 << ": " << e.marimi[i] << endl;
        }

        return out;
    }
};

int main() {
    int marimi[] = { 38, 40, 42 };

    EchipamentSportiv e1;
}