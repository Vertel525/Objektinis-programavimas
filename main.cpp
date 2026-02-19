#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::cin;
using std::vector;
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::endl;
using std::fixed;
using std::setprecision;
using std::sort;


struct Studentas {
    string vardas, pavarde;
    vector <int> paz;
    int egz;
    double vid;
    double med;
};
void inputas(vector <Studentas>& grupe);
void mediana(vector <Studentas>& grupe);
void outputas(const vector <Studentas>& grupe);
int main() {
    vector<Studentas> grupe;
    inputas(grupe);
    mediana(grupe);
    outputas(grupe);
}

void inputas(vector <Studentas>& grupe) {

    for (int ii = 0; ii < 2; ii++) {
        Studentas A;
        cout << "Iveskite studento vardo ir pavarde ";
        cin >> A.vardas >> A.pavarde;
        cout << "Iveskite semestro ivercius. Kiek ju bus? ";
        int n, sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int temp;
            cout << "Iveskite " << i + 1 << " pazymi is " << n << ": ";
            cin >> temp;
            A.paz.push_back(temp); sum += temp;
        }
        cout << "Iveskite egzamina: "; cin >> A.egz;
        A.vid = sum * 1 / (n * 1) * 0.4 + A.egz * 0.6;
        grupe.push_back(A);
        A.paz.clear();
    }
}

void mediana(vector<Studentas>& grupe)
{
    for (auto& A : grupe) {
        int n = A.paz.size();
       sort(A.paz.begin(), A.paz.end());

        if (n % 2 != 0) {
            A.med = A.paz[n / 2];
        }
        else A.med = (A.paz[n / 2 - 1] + A.paz[n / 2]) / 2.0;
    }


}
void outputas(const vector<Studentas>& grupe) {
    for (auto A : grupe) {
        cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde;
        //for(auto k: A.paz) cout<<setw(3)<<k;
        //cout<<setw(5)<<A.egz;
        cout << setw(10) << fixed << setprecision(2) << A.vid <<" "<<A.med;
    }
}
