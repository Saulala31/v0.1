#include "Studentas.h"

  studentas::~studentas(){ paz_.clear(); };
  studentas::studentas(const studentas& d){
    vardas_ = d.vardas_;
    pavarde_ = d.pavarde_;
    paz_sk_ = d.paz_sk_;
    egzaminas_ = d.egzaminas_;
    paz_suma_ = d.paz_suma_;
    vid_ = d.vid_;
    med_ = d.med_;
    paz_ = d.paz_;
  }
  studentas& studentas::operator=(const studentas& d) { // priskyrimo operatorius
    if (&d == this) return *this;
    vardas_ = d.vardas_;
    pavarde_ = d.pavarde_;
    paz_sk_ = d.paz_sk_;
    egzaminas_ = d.egzaminas_;
    paz_suma_ = d.paz_suma_;
    vid_ = d.vid_;
    med_ = d.med_;
    paz_ = d.paz_;
    return *this;
  }
  string studentas::Toline() const {
    string z = "";
      z += vardas_;
        z += string (20-vardas_.length(), ' ');
      z += pavarde_;
        z += string (20-pavarde_.length(), ' ');
    string zod_vid = to_string(vid_).substr(0, 4);
      z += zod_vid;
        z += string (20-zod_vid.length(), ' ');
    return z;
  }
  void studentas::setmed(double sk) {med_ = sk;}
  double studentas::getmed() const {return med_;}
  ///vid
  void studentas::setvid(double sk) {vid_ = sk;}
  double studentas::getvid() const {return vid_;}
  ///egzaminas
  void studentas::setegz(int sk) {egzaminas_ = sk;}
  int studentas::getegz() const {return egzaminas_;}
  ///paz_suma
  void studentas::setpaz_suma(int sk) {paz_suma_ = sk;}
  double studentas::getpaz_suma() const {return paz_suma_;}
  ///paz paz_sk
  void studentas::NewPaz(double sk) { paz_.push_back(sk);}
  void studentas::setPaz_Sk(int sk) {paz_sk_ = sk;}
  int studentas::getPaz_Sk() const {return paz_sk_;}
  ///Vardas Pavarde
  void studentas::setVardas(std::string name) {vardas_ = name;}
  void studentas::setPavarde(std::string surname) {pavarde_ = surname;}
  std::string studentas::vardas() const { return vardas_; } 
  std::string studentas::pavarde() const { return pavarde_; }