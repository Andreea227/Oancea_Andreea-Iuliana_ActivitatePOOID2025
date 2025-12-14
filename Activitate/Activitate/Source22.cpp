#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class DispozitivElectronic {
private:
    string denumire;
    float pret;
    int nrModule;
    int* module;
public:
    DispozitivElectronic() {
        this->denumire = "";
        this->pret = 0;
        this->nrModule = 0;
        this->module = nullptr;
    }

    DispozitivElectronic(string denumire, float pret, int nrModule, int* module) {
        this->denumire = denumire;
        this->pret = pret;
        this->nrModule = nrModule;

        this->module = new int[nrModule];
        for (int i = 0; i < nrModule; i++) {
            this->module[i] = module[i];
        }
    }

    DispozitivElectronic(const DispozitivElectronic& d) {
        this->denumire = d.denumire;
        this->pret = d.pret;
        this->nrModule = d.nrModule;

        this->module = new int[d.nrModule];
        for (int i = 0; i < d.nrModule; i++) {
            this->module[i] = d.module[i];
        }
    }

    DispozitivElectronic& operator=(const DispozitivElectronic& d) {
        if (this != &d) {
            this->denumire = d.denumire;
            this->pret = d.pret;
            this->nrModule = d.nrModule;

            delete[] this->module;
            this->module = new int[d.nrModule];
            for (int i = 0; i < d.nrModule; i++) {
                this->module[i] = d.module[i];
            }
        }
        return *this;
    }

    ~DispozitivElectronic() {
        delete[] this->module;
    }

    float getPret() const {
        return this->pret;
    }

    void setPret(float pret) {
        this->pret = pret;
    }

    bool operator!=(const DispozitivElectronic& d) const {
        return (this->denumire != d.denumire || this->pret != d.pret);
    }

    friend ostream& operator<<(ostream& out, const DispozitivElectronic& d) {
        out << "Dispozitiv: " << d.denumire << endl;
        out << "Pret: " << d.pret << " lei" << endl;
        out << "Numar module: " << d.nrModule << endl;
        for (int i = 0; i < d.nrModule; i++) {
            out << " Modul " << i + 1 << ": " << d.module[i] << endl;
        }
        return out;
    }
};

int main() {
    int module[] = { 101, 202, 303 };

    DispozitivElectronic d1;
    DispozitivElectronic d2("Router WiFi", 450.5, 3, module);

    cout << d2 << endl;
}