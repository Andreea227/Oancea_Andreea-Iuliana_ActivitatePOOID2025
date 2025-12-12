#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Magazin {
private:
    string nume;
    int nrProduse;
    float* preturi;
public:
    Magazin() {
        this->nume = "";
        this->nrProduse = 0;
        this->preturi = nullptr;
    }

    Magazin(string nume, int nrProduse, float* preturi) {
        this->nume = nume;
        this->nrProduse = nrProduse;

        this->preturi = new float[nrProduse];
        for (int i = 0; i < nrProduse; i++) {
            this->preturi[i] = preturi[i];
        }
    }

    Magazin(const Magazin& m) {
        this->nume = m.nume;
        this->nrProduse = m.nrProduse;

        this->preturi = new float[m.nrProduse];
        for (int i = 0; i < m.nrProduse; i++) {
            this->preturi[i] = m.preturi[i];
        }
    }

    ~Magazin() {
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }
    }

    int getNrProduse() const {
        return this->nrProduse;
    }

    void setNrProduse(int nr) {
        this->nrProduse = nr;
    }

    Magazin operator+(const Magazin& m) const {
        Magazin rez = *this;
        rez.nrProduse = this->nrProduse + m.nrProduse;
        return rez;
    }

    friend ostream& operator<<(ostream& out, const Magazin& m) {
        out << "Magazin: " << m.nume << endl;
        out << "Numar produse: " << m.nrProduse << endl;

        for (int i = 0; i < m.nrProduse; i++) {
            out << "  Pret produs " << i + 1 << ": " << m.preturi[i] << " lei" << endl;
        }

        return out;
    }
};
int main() {
    float preturi1[] = { 10.5, 20.0, 15.9 };
    float preturi2[] = { 5.5, 8.0 };
    Magazin mg1;
    Magazin mg2("MegaImage", 3, preturi1);
    Magazin mg3("Carrefour", 2, preturi2);
    cout << mg2 << endl;
}