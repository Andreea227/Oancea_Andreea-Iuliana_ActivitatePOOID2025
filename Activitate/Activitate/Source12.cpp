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
    Auto(string marca, string model, int ani, float* consumKm) {
        this->marca = marca;
        this->model = model;
        this->ani = ani;

        this->consumKm = new float[ani];
        for (int i = 0; i < ani; i++) {
            this->consumKm[i] = consumKm[i];
        }
    }
};