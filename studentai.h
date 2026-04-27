#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz = 0;
    double vid = 0.0;
    double med = 0.0;


    void skaiciuoti() {
        if (paz.empty()) return;

        double sum = 0;
        for (int x : paz) sum += x;

        vid = (sum / paz.size()) * 0.4 + egz * 0.6;

        std::sort(paz.begin(), paz.end());

        if (paz.size() % 2 == 0)
            med = (paz[paz.size() / 2 - 1] + paz[paz.size() / 2]) / 2.0;
        else
            med = paz[paz.size() / 2];

        med = med * 0.4 + egz * 0.6;
    }
};

#endif
