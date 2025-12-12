#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Notebook {
private:
    string brand;
    int nrPagini;
    int nrNote;
    string* note;
public:
    Notebook() {
        this->brand = "";
        this->nrPagini = 0;
        this->nrNote = 0;
        this->note = nullptr;
    }

    Notebook(string brand, int nrPagini, int nrNote, string* note) {
        this->brand = brand;
        this->nrPagini = nrPagini;
        this->nrNote = nrNote;

        this->note = new string[nrNote];
        for (int i = 0; i < nrNote; i++) {
            this->note[i] = note[i];
        }
    }

    Notebook(const Notebook& n) {
        this->brand = n.brand;
        this->nrPagini = n.nrPagini;
        this->nrNote = n.nrNote;

        this->note = new string[n.nrNote];
        for (int i = 0; i < n.nrNote; i++) {
            this->note[i] = n.note[i];
        }
    }

    ~Notebook() {
        if (this->note != nullptr) {
            delete[] this->note;
        }
    }

    int getNrPagini() const {
        return this->nrPagini;
    }

    void setNrPagini(int p) {
        this->nrPagini = p;
    }

    bool operator<(const Notebook& n) const {
        return this->nrPagini < n.nrPagini;
    }

    friend ostream& operator<<(ostream& out, const Notebook& n) {
        out << "Notebook brand: " << n.brand << endl;
        out << "Numar pagini: " << n.nrPagini << endl;
        out << "Numar note: " << n.nrNote << endl;

        for (int i = 0; i < n.nrNote; i++) {
            out << "  Nota " << i + 1 << ": " << n.note[i] << endl;
        }

        return out;
    }
};

int main() {

}