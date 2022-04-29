#include "Studentas.h"

void data::setmed(double sk) {med_ = sk;}
  double data::getmed() const {return med_;}
  ///vid
  void data::setvid(double sk) {vid_ = sk;}
  double data::getvid() const {return vid_;}
  ///egzaminas
  void data::setegz(int sk) {egzaminas_ = sk;}
  int data::getegz() const {return egzaminas_;}
  ///paz_suma
  void data::setpaz_suma(int sk) {paz_suma_ = sk;}
  double data::getpaz_suma() const {return paz_suma_;}
  ///paz paz_sk
  void data::NewPaz(double sk) { paz_.push_back(sk);}
  std::vector <int> data::getPaz() {return paz_;}
  void data::setPaz_Sk(int sk) {paz_sk_ = sk;}
  int data::getPaz_Sk() const {return paz_sk_;}
  ///Vardas Pavarde
  void data::setVardas(std::string name) {vardas_ = name;}
  void data::setPavarde(std::string surname) {pavarde_ = surname;}
  std::string data::vardas() const { return vardas_; } 
  std::string data::pavarde() const { return pavarde_; }