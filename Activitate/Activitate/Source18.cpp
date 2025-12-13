#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Rezervare {
private:
    string numeClient;
    int nrZile;
    float* costZilnic;
public:
    Rezervare() {
        numeClient = "";
        nrZile = 0;
        costZilnic = nullptr;
    }

};