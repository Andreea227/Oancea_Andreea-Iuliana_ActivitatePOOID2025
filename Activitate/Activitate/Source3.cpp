#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class AparatElectrocasnic {
private:
    string denumire;
    int consumW;
    int nrFunctii;
    int* timpFunctii;

public:
    AparatElectrocasnic() {
        this->denumire = "";
        this->consumW = 0;
        this->nrFunctii = 0;
        this->timpFunctii = nullptr;
    }
    AparatElectrocasnic(string denumire, int consumW, int nrFunctii, int* timpFunctii) {
        this->denumire = denumire;
        this->consumW = consumW;
        this->nrFunctii = nrFunctii;

        this->timpFunctii = new int[nrFunctii];
        for (int i = 0; i < nrFunctii; i++) {
            this->timpFunctii[i] = timpFunctii[i];
        }
    }
    AparatElectrocasnic(const AparatElectrocasnic& a) {
        this->denumire = a.denumire;
        this->consumW = a.consumW;
        this->nrFunctii = a.nrFunctii;

        this->timpFunctii = new int[a.nrFunctii];
        for (int i = 0; i < a.nrFunctii; i++) {
            this->timpFunctii[i] = a.timpFunctii[i];
        }
    }
    ~AparatElectrocasnic() {
        if (this->timpFunctii != nullptr) {
            delete[] this->timpFunctii;
        }
    }
    int getConsumW() const {
        return this->consumW;
    }
    void setConsumW(int consumNou) {
        this->consumW = consumNou;
    }
    friend ostream& operator<<(ostream& out, const AparatElectrocasnic& a) {
        out << "Denumire: " << a.denumire << endl;
        out << "Consum (W): " << a.consumW << endl;
        out << "Numar functii: " << a.nrFunctii << endl;

        for (int i = 0; i < a.nrFunctii; i++) {
            out << "  Timp functie " << i + 1 << ": " << a.timpFunctii[i] << " minute" << endl;
        }

        return out;
    }
};
int main() {
    int functii[] = { 15, 25, 40 }; 
    AparatElectrocasnic a1; 
    AparatElectrocasnic a2("Aspirator", 800, 3, functii); 
    cout << a2 << endl; 
    a2.setConsumW(900); 
    cout << "Consum nou: " << a2.getConsumW() << " W" << endl;
    AparatElectrocasnic a3 = a2; 
    cout << a3 << endl;
}