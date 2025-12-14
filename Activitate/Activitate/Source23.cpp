#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class VehiculElectric {
private:
    string model;
    float pret;
    int nrBaterii;
    int* capacitati;
public:
    VehiculElectric() {
        this->model = "";
        this->pret = 0;
        this->nrBaterii = 0;
        this->capacitati = nullptr;
    }
    VehiculElectric(string model, float pret, int nrBaterii, int* capacitati) {
        this->model = model;
        this->pret = pret;
        this->nrBaterii = nrBaterii;

        this->capacitati = new int[nrBaterii];
        for (int i = 0; i < nrBaterii; i++) {
            this->capacitati[i] = capacitati[i];
        }
    }
    VehiculElectric(const VehiculElectric& v) {
        this->model = v.model;
        this->pret = v.pret;
        this->nrBaterii = v.nrBaterii;

        this->capacitati = new int[v.nrBaterii];
        for (int i = 0; i < v.nrBaterii; i++) {
            this->capacitati[i] = v.capacitati[i];
        }
    }
    VehiculElectric& operator=(const VehiculElectric& v) {
        if (this != &v) {
            this->model = v.model;
            this->pret = v.pret;
            this->nrBaterii = v.nrBaterii;

            delete[] this->capacitati;
            this->capacitati = new int[v.nrBaterii];
            for (int i = 0; i < v.nrBaterii; i++) {
                this->capacitati[i] = v.capacitati[i];
            }
        }
        return *this;
    }
    ~VehiculElectric() {
        delete[] this->capacitati;
    }
    float getPret() const {
        return this->pret;
    }
    void setPret(float pret) {
        this->pret = pret;
    }
    bool operator!=(const VehiculElectric& v) const {
        return (this->model != v.model || this->pret != v.pret);
    }
    friend ostream& operator<<(ostream& out, const VehiculElectric& v) {
        out << "Vehicul: " << v.model << endl;
        out << "Pret: " << v.pret << " lei" << endl;
        out << "Numar baterii: " << v.nrBaterii << endl;
        for (int i = 0; i < v.nrBaterii; i++) {
            out << " Capacitate " << i + 1 << ": " << v.capacitati[i] << endl;
        }
        return out;
    }
};

int main() {
    int capacitati[] = { 50, 60 };

    VehiculElectric v1;
    VehiculElectric v2("Model E", 120000, 2, capacitati);

    cout << v2 << endl;

    v2.setPret(115000);
    cout << "Pret nou: " << v2.getPret() << " lei" << endl;

    VehiculElectric v3 = v2;
    cout << v3 << endl;

    if (v2 != v3) {
        cout << "v2 si v3 sunt diferite." << endl;
    }
    else {
        cout << "v2 si v3 sunt identice." << endl;
    }

    return 0;
}