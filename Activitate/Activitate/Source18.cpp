#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Rezervare {
private:
    string numeClient;
    int nrZile;
    float* costZilnic;
public:
    Rezervare() {
        numeClient = "";
        nrZile = 0;
        costZilnic = nullptr;
    }

    Rezervare(string numeClient, int nrZile, float* cost) {
        this->numeClient = numeClient;
        this->nrZile = nrZile;

        costZilnic = new float[nrZile];
        for (int i = 0; i < nrZile; i++) {
            costZilnic[i] = cost[i];
        }
    }

    Rezervare(const Rezervare& r) {
        numeClient = r.numeClient;
        nrZile = r.nrZile;

        costZilnic = new float[nrZile];
        for (int i = 0; i < nrZile; i++) {
            costZilnic[i] = r.costZilnic[i];
        }
    }
    Rezervare& operator=(const Rezervare& r) {
        if (this != &r) {
            delete[] costZilnic;

            numeClient = r.numeClient;
            nrZile = r.nrZile;

            costZilnic = new float[nrZile];
            for (int i = 0; i < nrZile; i++) {
                costZilnic[i] = r.costZilnic[i];
            }
        }
        return *this;
    }
    ~Rezervare() {
        delete[] costZilnic;
    }

    friend ostream& operator<<(ostream& out, const Rezervare& r) {
        out << "Client: " << r.numeClient << endl;
        out << "Zile: " << r.nrZile << endl;
        for (int i = 0; i < r.nrZile; i++) {
            out << "  Zi " << i + 1 << ": " << r.costZilnic[i] << " lei" << endl;
        }
        return out;
    }
};

int main() {
    float c[] = { 200, 180 };
    Rezervare r1("Popescu", 2, c);
    Rezervare r2;
    r2 = r1;
    cout << r2 << endl;
}