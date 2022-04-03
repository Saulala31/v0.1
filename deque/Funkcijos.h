#ifndef FUNKCIJOS
#define FUNKCIJOS

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <deque>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <chrono>


using std::cout; using std::cin; using std::string; using std::endl; using std::left; using std::fixed; using std::setprecision; using std::sort;
using std::setw; using std::ifstream;
using std::cout; using std::cin;
using std::endl; using std::string;
using std::deque; using std::istringstream;
using std::stringstream; using std::ofstream;
using std::to_string;

struct data{
    string vardas, pavarde;
    int egz = 0, paz_sk = 0 , paz_suma = 0;
    deque <int> paz;
    double vid, med = 0;
};
    void ivestis(deque<data>& temp);
    void nuskaitymas(deque <data> &temp, ifstream& df);
    bool palyginimas(const data& a, const data& b);
    void paskirstymas (deque <data> &temp);
    string PavertimasDidziosiomisR(string s);
    bool Ar_tai_yra_skaicius(string str);
    double Mediana(deque <int> a);
    void isvestis(deque<data> t);
    string zodziu_sujungimas(string v, string v2);
    void FailuGeneravimas( int kiek, int pazsk);
    void skirstymas(deque <data> & var, deque <data> & gal, deque <data> temp, int moksk);
    void FailuIsvedimas(deque <data> & var, deque <data> & gal);
    #endif
