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
};