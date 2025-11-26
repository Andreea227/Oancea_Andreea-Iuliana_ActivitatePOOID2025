#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
 
using namespace std;
class Masina {
public:
    string marca;
    int anFabricatie;
    const int nrRoti;      
    static int totalMasini; 
    float* preturi;      
    int nrPreturi;
};