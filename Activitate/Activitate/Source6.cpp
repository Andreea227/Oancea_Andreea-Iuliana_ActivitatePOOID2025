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

    friend ostream& operator<<(ostream& out, const AparatAer& a) {
        out << "Model: " << a.model << endl;
        out << "Putere: " << a.putereW << " W" << endl;
        out << "Nr viteze: " << a.nrViteze << endl;
        for (int i = 0; i < a.nrViteze; i++)
            out << "  Viteza " << i + 1 << ": " << a.viteze[i] << endl;
        return out;
    }
    bool operator==(const AparatAer& a) const {
        return this->putereW == a.putereW;
    }
};
int main() {
    int viteze[] = { 1, 2, 3 };
    AparatAer a1;
    AparatAer a2("VentilatorX", 120, 3, viteze);
    cout << a2 << endl;
    a2.setPutere(150);
    cout << "Putere noua: " << a2.getPutere() << " W" << endl;
    AparatAer a3 = a2;
    cout << a3 << endl;
    if (a2 == a3)
        cout << "a2 si a3 au aceeasi putere." << endl;
    else
        cout << "a2 si a3 au putere diferita." << endl;
    return 0;
}