#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class AparatAudio {
private:
    string marca;
    int putereW;
    int nrModele;
    int* aniModele;
public:
    AparatAudio() {
        this->marca = "";
        this->putereW = 0;
        this->nrModele = 0;
        this->aniModele = nullptr;
    }
    AparatAudio(string marca, int putereW, int nrModele, int* aniModele) {
        this->marca = marca;
        this->putereW = putereW;
        this->nrModele = nrModele;

        this->aniModele = new int[nrModele];
        for (int i = 0; i < nrModele; i++) {
            this->aniModele[i] = aniModele[i];
        }
    }
    AparatAudio(const AparatAudio& a) {
        this->marca = a.marca;
        this->putereW = a.putereW;
        this->nrModele = a.nrModele;

        this->aniModele = new int[a.nrModele];
        for (int i = 0; i < a.nrModele; i++) {
            this->aniModele[i] = a.aniModele[i];
        }
    }
    ~AparatAudio() {
        if (this->aniModele != nullptr) {
            delete[] this->aniModele;
        }
    }
    int getPutereW() const {
        return this->putereW;
    }
    void setPutereW(int nouaPutere) {
        this->putereW = nouaPutere;
    }
    friend ostream& operator<<(ostream& out, const AparatAudio& a) {
        out << "Marca: " << a.marca << endl;
        out << "Putere (W): " << a.putereW << endl;
        out << "Numar modele: " << a.nrModele << endl;
        for (int i = 0; i < a.nrModele; i++) {
            out << "  Model " << i + 1 << ": anul " << a.aniModele[i] << endl;
        }
        return out;
    }
    AparatAudio operator+(int x) const {
        AparatAudio copie = *this;
        copie.putereW += x;
        return copie;
    }

};
int main() {
    int ani[] = { 2018, 2020, 2022 };
    AparatAudio a1;
    AparatAudio a2("AudioTech", 150, 3, ani);
    cout << "Aparat initial:" << endl;
    cout << a2 << endl;
    a2.setPutereW(200);
    cout << "Putere noua: " << a2.getPutereW() << " W" << endl;
    AparatAudio a3 = a2;
    cout << "Obiect copiat:" << endl;
    cout << a3 << endl;
    AparatAudio a4 = a3 + 50;
}
