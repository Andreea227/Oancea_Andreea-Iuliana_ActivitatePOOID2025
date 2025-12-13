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

    Rezervare(string numeClient, int nrZile, float* cost) {
        this->numeClient = numeClient;
        this->nrZile = nrZile;

        costZilnic = new float[nrZile];
        for (int i = 0; i < nrZile; i++) {
            costZilnic[i] = cost[i];
        }
    }
};