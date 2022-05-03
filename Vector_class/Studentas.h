#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <chrono>

using std::cout; using std::cin; using std::left; using std::fixed; using std::setprecision; using std::sort; using std::setw; using std::ifstream;
using std::endl; using std::string; using std::vector; using std::istringstream; using std::stringstream; using std::ofstream; using std::to_string;

class data {
private:
  string vardas_;
  string pavarde_;
  int paz_sk_;
  int egzaminas_;
  int paz_suma_;
  double vid_;
  double med_;
  vector<int> paz_;
public:
  data(){
    paz_sk_ = 0;
    egzaminas_ = 0;
    paz_suma_ = 0;
    vid_ = 0;
    med_ = 0;
   }  // default konstruktorius
  ~data();
  data(const data& d);
  data& operator = (const data& d);
  void setmed(double sk);
  double getmed() const;
  ///vid
  void setvid(double sk);
  double getvid() const;
  ///egzaminas
  void setegz(int sk);
  int getegz() const;
  ///paz_suma
  void setpaz_suma(int sk);
  double getpaz_suma() const;
  ///paz paz_sk
  void NewPaz(double sk);
  vector <int> getPaz();
  void setPaz_Sk(int sk);
  int getPaz_Sk() const;
  ///Vardas Pavarde
  void setVardas(string name);
  void setPavarde(string surname);
  string vardas() const; 
  string pavarde() const;
};

void ivestis(vector<data>& temp);
    void nuskaitymas(vector <data> &temp, ifstream& df);
    bool palyginimas(const data& a, const data& b);
    void paskirstymas (vector <data> &temp);
    string PavertimasDidziosiomisR(string s);
    bool Ar_tai_yra_skaicius(string str);
    double Mediana(vector <int> a);
    void isvestis(vector<data> t);
    string zodziu_sujungimas(string v, string v2);
    void FailuGeneravimas( int kiek, int pazsk);
    void skirstymas(vector <data> & var, vector <data> & gal, vector <data> temp, int moksk);
    void FailuIsvedimas(vector <data> & var, vector <data> & gal);

    #endif