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

};