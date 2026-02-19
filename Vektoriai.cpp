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

void inranka(vector <Studentas>& grupe);
void outputas(const vector <Studentas>& grupe, char& rez);

int main() {
    vector<Studentas> grupe;
    char rez;
    inranka(grupe);
    outputas(grupe, rez);
}

void inranka(vector <Studentas>& grupe) {

    while (true) {
        Studentas A;
        int sum = 0;
        cout << "Iveskite studento vardo ir pavarde. Norint baigti studentu ivedima, iveskite 0: ";
        cin >> A.vardas >> A.pavarde;

        if (A.vardas == "0" || A.pavarde == "0") {
            break;
        }
        int temp;
        cout << "Iveskite pazymius nuo 1 iki 10. Norint baigti pazymiu ivedima, iveskite 0: ";

        while (true) {
            if (cin >> temp) {
                if (temp == 0) {
                    break;
                }
                if (temp >= 1 && temp <= 10) {
                    A.paz.push_back(temp);
                    sum += temp;
                }
                else {
                    cout << "Neteisingas pazymys, iveskite 1-10 arba 0: ";
                }
            }
            else {
                cout << "Neteisingas ivedimas, iveskite skaiciu: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        cout << "Iveskite egzamino rezultata: ";
        while (true) {
            if (cin >> A.egz && A.egz >= 1 && A.egz <= 10) {
                break;
            }
            else {
                cout << "Neteisingas ivedimas, iveskite skaiciu nuo 1 iki 10: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        int n = A.paz.size();
        A.vid = sum * 1.0 / (n * 1.0) * 0.4 + A.egz * 0.6;
        A.paz.clear();

        for (auto& A : grupe) {
            int n = A.paz.size();
            sort(A.paz.begin(), A.paz.end());

            if (n % 2 != 0) {
                A.med = A.paz[n / 2];
                A.med = A.paz[n / 2];
            }
            else if(n > 0){
                A.med = (A.paz[n / 2 - 1] + A.paz[n / 2]) / 2.0;
                A.med = A.med * 0.4 + A.egz * 0.6;

            }

        }
        grupe.push_back(A);
    }
}
void outputas(const vector<Studentas>& grupe, char &rez) {
    cout << "Rezultata isvesti su mediana(irasyti M arba m) ar vidurkiu(irasyti V arba v)";
    cin >> rez;
    while (true) {
        if (rez == 'V' || rez == 'v' || rez == 'M' || rez == 'm') {
            break;
        }
        else {
            cout << "Neteisingas ivedimas, iveskite v arba m: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    if (rez == 'V' || rez == 'v') {
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(10) << "vidurkis" << endl;
        for (auto A : grupe) {

            cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde;
            cout << left << setw(10) << fixed << setprecision(2) << A.vid << endl;
        }
    }
    if (rez == 'M' || rez == 'm') {
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << left << setw(10) << "mediana" << endl;

        for (auto A : grupe) {

            cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde;
            cout << setw(10) << fixed << setprecision(2) << A.med << endl;
        }
    }
}
