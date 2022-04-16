#ifndef FUNKCIJOS
#define FUNKCIJOS

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <chrono>
#include <list>
#include <iterator>

using std::cout; using std::cin; using std::string; using std::endl; using std::left; using std::fixed; using std::setprecision; using std::sort;
using std::setw; using std::ifstream;
using std::cout; using std::cin;
using std::endl; using std::string;
using std::istringstream;
using std::stringstream; using std::ofstream;
using std::to_string; using std::list; using std::advance;

struct data{
    string vardas, pavarde;
    int egz = 0, paz_sk = 0 , paz_suma = 0;
    list <int> paz;
    double vid, med = 0;
};
    void ivestis(list<data>& temp);
    void nuskaitymas(list <data> &temp, ifstream& df);
    void paskirstymas (list <data> &temp);
    string PavertimasDidziosiomisR(string s);
    bool Ar_tai_yra_skaicius(string str);
    double Mediana(list <int> a);
    void isvestis(list<data> t);
    string zodziu_sujungimas(string v, string v2);
    void FailuGeneravimas( int kiek, int pazsk);
    void skirstymas(list <data> & var, list <data> & temp, int moksk);
    void FailuIsvedimas(list <data> & var, list <data> & gal);
    #endif
