#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Auto {
private:
    string marca;
    string model;
    int ani;
    float* consumKm;
public:
    Auto() {
        this->marca = "";
        this->model = "";
        this->ani = 0;
        this->consumKm = nullptr;
    }

};