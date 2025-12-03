#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Imprimanta {
private:
    string model;
    int vitezaPagini;
    int nrCartuse;
    int* nivelCartuse;
public:
    Imprimanta() {
        model = "";
        vitezaPagini = 0;
        nrCartuse = 0;
        nivelCartuse = nullptr;
    }
};