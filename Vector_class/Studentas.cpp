#include "Studentas.h"

  data::~data(){ paz_.clear(); };
  data::data(const data& d){
    vardas_ = d.vardas_;
    pavarde_ = d.pavarde_;
    paz_sk_ = d.paz_sk_;
    egzaminas_ = d.egzaminas_;
    paz_suma_ = d.paz_suma_;
    vid_ = d.vid_;
    med_ = d.med_;
    paz_ = d.paz_;
  }
  data& data::operator=(const data& d) { // priskyrimo operatorius
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
  string data::Toline() const {
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