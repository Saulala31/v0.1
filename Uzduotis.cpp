#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

struct data{
    string vardas, pavarde;
    int paz[50], egz, paz_sk = 0;
    double rezult;
    data *next;
};

void ivestis(data& temp);
void isvestis(data*);
void add_mok(data *&root);
string PavertimasDidziosiomisR(string s);
bool Ar_tai_yra_skaicius(string str);

int main(){
    data *root = NULL;
    int k=0;
    string sk("T");
    while (sk !="N"){
        cout << "Jei norite prideti mokini rasykite: T, jei ne rasykite: N"<<endl;
        cin >> sk;
          sk = PavertimasDidziosiomisR(sk);
            if (sk=="N") break;
            else if (sk=="T") add_mok(*&root);
            else cout << "ivedete neteisinga reiksme" << endl;
    }

    isvestis(root);

    delete[] root;

    return 0;
}
void ivestis(data& temp){
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    string n("T");
    cout << "Veskite mokinio pazymius"<< endl << "Pazymiai gali buti tik tarp 1-10"<<endl<<
     "Noredami uzbaigti pazymiu vedima irasykite: B"<<endl; 
    while(n!="B"){
        cin >> n;
        n = PavertimasDidziosiomisR(n);
        if (n == "B") break;
        else if (!Ar_tai_yra_skaicius(n)){
          cout << "Jus ivedete ne skaiciu, bandykite vel :)"<<endl;
        }
        else {
          int x = stoi(n);
          if (x > 10 or x<1) cout << "ivestas skaicius neatitinka kriterijaus"<<endl;
          else {
              temp.paz[temp.paz_sk] = x;
              temp.paz_sk++;
          }
        }
    }
    n.assign("T");
    cout << "iveskite egzamino pazymi: ";
    while(!Ar_tai_yra_skaicius(n)){
        cin >> n;
        if (!Ar_tai_yra_skaicius(n)){
          cout << "Jus ivedete ne skaiciu, bandykite vel :)"<<endl;
        }
        else {
          int x = stoi(n);
          if (x > 10 or x<1){
             cout << "ivestas skaicius neatitinka kriterijaus"<<endl;
             n.assign("T");
          }
          else {
              temp.paz[temp.paz_sk] = x;
              temp.paz_sk++;
              break;
          }
        }
    }
}   

void isvestis(data *root){
  data *t = root;
  while (t) {
    cout << std::setw(20) << t->vardas << std::setw(20) << t->pavarde;
    for (int i = 0; i<t->paz_sk; i++) cout << std::setw(10) << t->paz[i];
    cout << std::setw(10) << t->egz << std::endl;
    t = t->next;
  }
  cout << endl;
}

void add_mok(data *&root){
  if (root) {
    data *t = root;
    while (t->next) t = t->next;
    t->next = new data;
    t = t->next;
    ivestis(*t);
    //t->data = rand()%10;
    t->next = NULL;
  }
  else {
    root = new data;
    ivestis(*root);
    //root->data = rand()%10;
    root->next = NULL;
  }
}
string PavertimasDidziosiomisR(string s){
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return toupper(c); });
    return s;
}
bool Ar_tai_yra_skaicius(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}
