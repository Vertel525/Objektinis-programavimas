#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include "funkcijos.h"

using namespace std;

template <typename Container>
void testuoti(const string& failas) {

    Container studentai;
    Container vargsiukai;
    Container kietiakai;
