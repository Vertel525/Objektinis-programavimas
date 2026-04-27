#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <type_traits>

template <typename Container>
void skaityti(Container& grupe, const std::string& failas) {

    grupe.clear();
    std::ifstream in(failas);

    std::string line;
    getline(in, line);

    while (getline(in, line)) {
        std::istringstream iss(line);
        Studentas A;

        iss >> A.vardas >> A.pavarde;

        int x;
        std::vector<int> visi;

        while (iss >> x) visi.push_back(x);

        if (visi.empty()) continue;

        A.egz = visi.back();
        visi.pop_back();
        A.paz = visi;

        A.skaiciuoti();

        grupe.push_back(A);
    }
}
