#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class InstalatieIndustriala {
private:
    string tip;
    int capacitate;
    int nrComponente;
    int* componente;
public:
    InstalatieIndustriala() {
        this->tip = "";
        this->capacitate = 0;
        this->componente = 0;
        this->componente = nullptr;
    }
    InstalatieIndustriala(string tip, int capacitate, int nrComponente, int* componente) {
        this->tip = tip;
        this->capacitate = capacitate;
        this->nrComponente = nrComponente;
        this->componente = new int[nrComponente];
        for (int i = 0; i < nrComponente; i++) {
            this->componente[i] = componente[i];
        }
    }
    InstalatieIndustriala(const InstalatieIndustriala& i) {
        this->tip = i.tip;
        this->capacitate = i.capacitate;
        this->nrComponente = i.nrComponente;
        this->componente = new int[i.nrComponente];
        for (int j = 0; j < i.nrComponente; j++) {
            this->componente[j] = i.componente[j];
        }
    }
    ~InstalatieIndustriala() {
        if (this->componente != nullptr) {
            delete[] this->componente;
        }
    }
    int getCapacitate() const {
        return this->capacitate;
    }
    void setCapacitate(int capacitateNoua) {
        this->capacitate = capacitateNoua;
    }
    bool operator==(const InstalatieIndustriala& i) const {
        return this->capacitate == i.capacitate &&
            this->nrComponente == i.nrComponente;
    }
    friend ostream& operator<<(ostream& out, const InstalatieIndustriala& i) {
        out << "Tip: " << i.tip << endl;
        out << "Capacitate: " << i.capacitate << endl;
        out << "Numar componente: " << i.nrComponente << endl;
        for (int j = 0; j < i.nrComponente; j++) {
            out << "  Componenta " << j + 1 << ": " << i.componente[j] << endl;
        }
        return out;
    }
};
int main() {
    int comp[] = { 10, 20, 30, 40 };
    InstalatieIndustriala i1;
    InstalatieIndustriala i2("Presiune Mare", 200, 4, comp);
    cout << "Instalatie initiala:" << endl;
    cout << i2 << endl;
    i2.setCapacitate(250);
    cout << "Capacitate noua: " << i2.getCapacitate() << endl;
    InstalatieIndustriala i3 = i2;
    cout << "Instalatie copiata:" << endl;
    cout << i3 << endl;
}