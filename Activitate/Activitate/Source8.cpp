#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Imprimanta {
private:
    string model;
    int vitezaPagini;
    int nrCartuse;
    int* nivelCartuse;
public:
    Imprimanta() {
        model = "";
        vitezaPagini = 0;
        nrCartuse = 0;
        nivelCartuse = nullptr;
    }
    Imprimanta(string model, int vitezaPagini, int nrCartuse, int* nivelCartuse) {
        this->model = model;
        this->vitezaPagini = vitezaPagini;
        this->nrCartuse = nrCartuse;
        this->nivelCartuse = new int[nrCartuse];
        for (int i = 0; i < nrCartuse; i++)
            this->nivelCartuse[i] = nivelCartuse[i];
    }
    Imprimanta(const Imprimanta& i) {
        model = i.model;
        vitezaPagini = i.vitezaPagini;
        nrCartuse = i.nrCartuse;
        nivelCartuse = new int[i.nrCartuse];
        for (int j = 0; j < i.nrCartuse; j++)
            nivelCartuse[j] = i.nivelCartuse[j];
    }
    ~Imprimanta() {
        if (nivelCartuse != nullptr)
            delete[] nivelCartuse;
    }
    int getViteza() const {
        return vitezaPagini; }

    void setViteza(int v) {
        vitezaPagini = v; }

    friend ostream& operator<<(ostream& out, const Imprimanta& i) {
        out << "Model: " << i.model << endl;
        out << "Viteza pagini: " << i.vitezaPagini << endl;
        out << "Nr cartuse: " << i.nrCartuse << endl;
        for (int j = 0; j < i.nrCartuse; j++)
            out << "  Nivel cartus " << j + 1 << ": " << i.nivelCartuse[j] << endl;
        return out;
    }
    bool operator!=(const Imprimanta& i) const {
        return this->vitezaPagini != i.vitezaPagini;
    }
};
int main() {
    int nivel[] = { 80, 60, 90 };
    Imprimanta imp1;
    Imprimanta imp2("HP", 20, 3, nivel);
    cout << imp2 << endl;
}