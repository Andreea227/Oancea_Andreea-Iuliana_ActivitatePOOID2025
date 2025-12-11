#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Ornament {
private:
    string nume;
    float pret;
    int nrMateriale;
    string* materiale;
public:
    Ornament() {
        this->nume = "";
        this->pret = 0;
        this->nrMateriale = 0;
        this->materiale = nullptr;
    }
    Ornament(string nume, float pret, int nrMateriale, string* materiale) {
        this->nume = nume;
        this->pret = pret;
        this->nrMateriale = nrMateriale;

        this->materiale = new string[nrMateriale];
        for (int i = 0; i < nrMateriale; i++) {
            this->materiale[i] = materiale[i];
        }
    }
    Ornament(const Ornament& o) {
        this->nume = o.nume;
        this->pret = o.pret;
        this->nrMateriale = o.nrMateriale;

        this->materiale = new string[o.nrMateriale];
        for (int i = 0; i < o.nrMateriale; i++) {
            this->materiale[i] = o.materiale[i];
        }
    }
    ~Ornament() {
        if (this->materiale != nullptr) {
            delete[] this->materiale;
        }
    }
    float getPret() const {
        return this->pret;
    }
    void setPret(float p) {
        this->pret = p;
    }
    bool operator==(const Ornament& o) const {
        return (this->nume == o.nume && this->pret == o.pret);
    }
    friend ostream& operator<<(ostream& out, const Ornament& o) {
        out << "Nume: " << o.nume << endl;
        out << "Pret: " << o.pret << " lei" << endl;
        out << "Numar materiale: " << o.nrMateriale << endl;

        for (int i = 0; i < o.nrMateriale; i++) {
            out << "  Material " << i + 1 << ": " << o.materiale[i] << endl;
        }
        return out;
    }
};
int main() {
    string materiale[] = { "Plastic", "Metal", "Sticla" };
    Ornament o1;
    Ornament o2("Glob", 15.5, 3, materiale);
}