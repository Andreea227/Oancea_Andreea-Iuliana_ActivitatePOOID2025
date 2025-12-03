#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Instalatie {
private:
    string tip;
    int nrComponente;
    int capacitate;
    int* componente;
public:
    Instalatie() {
        tip = "";
        nrComponente = 0;
        capacitate = 0;
        componente = nullptr;
    }
    Instalatie(string tip, int nrComponente, int capacitate, int* comp) {
        this->tip = tip;
        this->nrComponente = nrComponente;
        this->capacitate = capacitate;
        this->componente = new int[nrComponente];
        for (int i = 0; i < nrComponente; i++)
            this->componente[i] = comp[i];
    }
    Instalatie(const Instalatie& i) {
        tip = i.tip;
        nrComponente = i.nrComponente;
        capacitate = i.capacitate;
        componente = new int[i.nrComponente];
        for (int j = 0; j < i.nrComponente; j++)
            componente[j] = i.componente[j];
    }
    ~Instalatie() {
        if (componente != nullptr)
            delete[] componente;
    }
    int getCapacitate() const { 
        return capacitate; }

    void setCapacitate(int c) { 
        capacitate = c; }

    friend ostream& operator<<(ostream& out, const Instalatie& i) {
        out << "Tip: " << i.tip << endl;
        out << "Nr componente: " << i.nrComponente << endl;
        out << "Capacitate: " << i.capacitate << endl;
        for (int j = 0; j < i.nrComponente; j++)
            out << "  Componenta " << j + 1 << ": " << i.componente[j] << endl;
        return out;
    }
    bool operator==(const Instalatie& i) const {
        return this->capacitate == i.capacitate;
    }
};
int main() {
    int comp[] = { 1, 2, 3, 4 };
}