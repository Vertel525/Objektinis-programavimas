#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentai1.h"
#include <string>
#include <list>
#include <deque>

template <typename Container>
void skaityti(Container& grupe, const std::string& failas);

template <typename Container>
void rikiuoti(Container& grupe);

template <typename Container>
void skirstyti1(const Container& grupe, Container& vargsiukai, Container& kietiakai);

template <typename Container>
void skirstyti2(Container& studentai, Container& vargsiukai);

template <typename Container>
void skirstyti3(Container& studentai, Container& vargsiukai);

template <typename Container>
void isvestifaila(const Container& grupe, const std::string& failas);

void generuotifaila(int kiek, const std::string& failas);

#include "funkcijos1.cpp"

#endif
