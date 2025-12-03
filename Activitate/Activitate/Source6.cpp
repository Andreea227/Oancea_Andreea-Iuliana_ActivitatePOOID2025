#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class AparatAer {
private:
    string model;
    int putereW;
    int nrViteze;
    int* viteze;
public:
    AparatAer() {
        this->model = "";
        this->putereW = 0;
        this->nrViteze = 0;
        this->viteze = nullptr;
    }
    AparatAer(string model, int putereW, int nrViteze, int* viteze) {
        this->model = model;
        this->putereW = putereW;
        this->nrViteze = nrViteze;
        this->viteze = new int[nrViteze];
        for (int i = 0; i < nrViteze; i++)
            this->viteze[i] = viteze[i];
    }
};