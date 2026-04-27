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
template <typename Container>
void rikiuoti(Container& grupe) {

    auto cmp = [](const Studentas& a, const Studentas& b) {
        return a.vid < b.vid;
    };

    if constexpr (std::is_same<Container, std::list<Studentas>>::value)
        grupe.sort(cmp);
    else
        std::sort(grupe.begin(), grupe.end(), cmp);
}
template <typename Container>
void skirstyti1(const Container& grupe, Container& vargsiukai, Container& kietiakai) {

    for (const auto& s : grupe) {
        if (s.vid < 5.0) vargsiukai.push_back(s);
        else kietiakai.push_back(s);
    }
}
template <typename Container>
void skirstyti2(Container& studentai, Container& vargsiukai) {

    auto it = studentai.begin();

    while (it != studentai.end()) {
        if (it->vid < 5.0) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        }
        else {
            ++it;
        }
    }
}
template <typename Container>
void skirstyti3(Container& studentai, Container& vargsiukai) {

    if constexpr (std::is_same<Container, std::list<Studentas>>::value) {
        for (auto it = studentai.begin(); it != studentai.end();) {
            if (it->vid < 5.0)
                vargsiukai.splice(vargsiukai.end(), studentai, it++);
            else
                ++it;
        }
    }
    else {
        auto it = std::partition(studentai.begin(), studentai.end(),
            [](const Studentas& s) { return s.vid >= 5.0; });

        vargsiukai.insert(vargsiukai.end(), it, studentai.end());
        studentai.erase(it, studentai.end());
    }
}
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
template <typename Container>
void rikiuoti(Container& grupe) {

    auto cmp = [](const Studentas& a, const Studentas& b) {
        return a.vid < b.vid;
    };

    if constexpr (std::is_same<Container, std::list<Studentas>>::value)
        grupe.sort(cmp);
    else
        std::sort(grupe.begin(), grupe.end(), cmp);
}
template <typename Container>
void skirstyti1(const Container& grupe, Container& vargsiukai, Container& kietiakai) {

    for (const auto& s : grupe) {
        if (s.vid < 5.0) vargsiukai.push_back(s);
        else kietiakai.push_back(s);
    }
}
template <typename Container>
void skirstyti2(Container& studentai, Container& vargsiukai) {

    auto it = studentai.begin();

    while (it != studentai.end()) {
        if (it->vid < 5.0) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        }
        else {
            ++it;
        }
    }
}
template <typename Container>
void skirstyti3(Container& studentai, Container& vargsiukai) {

    if constexpr (std::is_same<Container, std::list<Studentas>>::value) {
        for (auto it = studentai.begin(); it != studentai.end();) {
            if (it->vid < 5.0)
                vargsiukai.splice(vargsiukai.end(), studentai, it++);
            else
                ++it;
        }
    }
    else {
        auto it = std::partition(studentai.begin(), studentai.end(),
            [](const Studentas& s) { return s.vid >= 5.0; });

        vargsiukai.insert(vargsiukai.end(), it, studentai.end());
        studentai.erase(it, studentai.end());
    }
}
template <typename Container>
void isvestifaila(const Container& grupe, const std::string& failas) {
    std::ofstream out(failas);
    for (const auto& s : grupe)
        out << s.vardas << " " << s.pavarde << " " << s.vid << "\n";
}
