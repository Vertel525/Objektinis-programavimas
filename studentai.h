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
};

#endif
