#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Tranzactie {
private:
    string tip;
    int nrSume;
    float* sume;
public:
    Tranzactie() {
        tip = "";
        nrSume = 0;
        sume = nullptr;
    }

    Tranzactie(string tip, int nrSume, float* sume) {
        this->tip = tip;
        this->nrSume = nrSume;

        this->sume = new float[nrSume];
        for (int i = 0; i < nrSume; i++) {
            this->sume[i] = sume[i];
        }
    }

    Tranzactie(const Tranzactie& t) {
        tip = t.tip;
        nrSume = t.nrSume;

        sume = new float[nrSume];
        for (int i = 0; i < nrSume; i++) {
            sume[i] = t.sume[i];
        }
    }

    ~Tranzactie() {
        delete[] sume;
    }

    int getNrSume() const {
        return nrSume;
    }

    void setNrSume(int nr) {
        nrSume = nr;
    }

    Tranzactie operator+(const Tranzactie& t) const {
        Tranzactie rez = *this;
        rez.nrSume = this->nrSume + t.nrSume;
        return rez;
    }

    friend ostream& operator<<(ostream& out, const Tranzactie& t) {
        out << "Tranzactie: " << t.tip << endl;
        out << "Numar sume: " << t.nrSume << endl;
        return out;
    }
};

int main() {
    float s1[] = { 100, 200 };
    float s2[] = { 50 };

    Tranzactie t1("Plata", 2, s1);
    Tranzactie t2("Incasare", 1, s2);

    cout << "Nr sume t1: " << t1.getNrSume() << endl;
    Tranzactie t3 = t1 + t2;

    cout << t3 << endl;
}