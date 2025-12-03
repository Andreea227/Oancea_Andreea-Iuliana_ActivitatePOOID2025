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
    AparatAer(const AparatAer& a) {
        this->model = a.model;
        this->putereW = a.putereW;
        this->nrViteze = a.nrViteze;
        this->viteze = new int[a.nrViteze];
        for (int i = 0; i < a.nrViteze; i++)
            this->viteze[i] = a.viteze[i];
    }
    ~AparatAer() {
        if (viteze != nullptr)
            delete[] viteze;
    }
    int getPutere() const { 
        return putereW; }

    void setPutere(int w) {
        putereW = w; }

};