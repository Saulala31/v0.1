#pragma once

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
#include "vector.h"
using std::cout; using std::cin; using std::left; using std::fixed; using std::setprecision; using std::sort; using std::setw; using std::ifstream;
using std::endl; using std::string; using std::istringstream; using std::stringstream; using std::ofstream; using std::to_string;

class Zmogus{
  protected:
    string vardas_;
    string pavarde_;

  public:
    Zmogus() : vardas_(""), pavarde_("") {}
    Zmogus(string vardas_, string pavarde_);

    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }

    virtual void setVardas(string vardas) = 0;
    virtual void setPavarde(string pavarde) = 0;

};

class studentas : public Zmogus {
private:
  int paz_sk_;
  int egzaminas_;
  int paz_suma_;
  double vid_;
  double med_;
  Vector<int> paz_;
public:
  studentas(){
    paz_sk_ = 0;
    egzaminas_ = 0;
    paz_suma_ = 0;
    vid_ = 0;
    med_ = 0;
   }  // default konstruktorius
  ~studentas();
  studentas(const studentas& d);
  studentas& operator = (const studentas& d);
  studentas (int paz_sk_, int egzaminas_, int paz_suma_, double vid_, double med_, Vector<int> paz_, string vardas_, string pavarde_ ) : Zmogus(vardas_, pavarde_) {}

  string Toline() const;
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
  Vector <int> getPaz() {return paz_;};
  void setPaz_Sk(int sk);
  int getPaz_Sk() const;
  ///Vardas Pavarde
  void setVardas(string name);
  void setPavarde(string surname);
  string vardas() const; 
  string pavarde() const;
};

    void ivestis(Vector<studentas>& temp);
    void nuskaitymas(Vector <studentas> &temp, ifstream& df);
    bool palyginimas(const studentas& a, const studentas& b);
    void paskirstymas (Vector <studentas> &temp);
    string PavertimasDidziosiomisR(string s);
    bool Ar_tai_yra_skaicius(string str);
    double Mediana(Vector <int> a);
    void isvestis(Vector<studentas> t);
    string zodziu_sujungimas(string v, string v2);
    void FailuGeneravimas( int kiek, int pazsk);
    void skirstymas(Vector <studentas> & var, Vector <studentas> & gal, Vector <studentas> temp, int moksk);
    void FailuIsvedimas(Vector <studentas> & var, Vector <studentas> & gal);