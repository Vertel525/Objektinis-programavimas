#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include "funkcijos1.h"

using namespace std;

template <typename Container>
void testuoti(const string& failas) {

    Container studentai;
    Container vargsiukai;
    Container kietiakai;

    cout << "\nTESTAS: " << failas << endl;

    auto t1 = chrono::high_resolution_clock::now();
    skaityti(studentai, failas);
    auto t2 = chrono::high_resolution_clock::now();

    cout << "Skaitymas: " << chrono::duration<double>(t2 - t1).count() << endl;

    auto t3 = chrono::high_resolution_clock::now();
    rikiuoti(studentai);
    auto t4 = chrono::high_resolution_clock::now();

    cout << "Rikiavimas: " << chrono::duration<double>(t4 - t3).count() << endl;

    auto s1 = chrono::high_resolution_clock::now();
    skirstyti1(studentai, vargsiukai, kietiakai);
    auto e1 = chrono::high_resolution_clock::now();

    cout << "Strategija 1: " << chrono::duration<double>(e1 - s1).count() << endl;

    studentai.clear();
    skaityti(studentai, failas);
    vargsiukai.clear();

    auto s2 = chrono::high_resolution_clock::now();
    skirstyti2(studentai, vargsiukai);
    auto e2 = chrono::high_resolution_clock::now();

    cout << "Strategija 2: " << chrono::duration<double>(e2 - s2).count() << endl;

    studentai.clear();
    skaityti(studentai, failas);
    vargsiukai.clear();
