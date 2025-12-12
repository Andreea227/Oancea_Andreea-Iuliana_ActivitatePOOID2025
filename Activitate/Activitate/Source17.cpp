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
};