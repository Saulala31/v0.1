#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>
using std::cout; using std::cin; using std::string; using std::endl; using std::left; using std::fixed; using std::setprecision; using std::sort;
using std:: vector; using std::setw;
struct data{
    string vardas, pavarde;
    int paz[51] = {0}, egz = 0, paz_sk = 0;
    double vid, med = 0;
    data *next;
};

void ivestis(vector<data>& temp);
void isvestis(vector<data> t);
string PavertimasDidziosiomisR(string s);
bool Ar_tai_yra_skaicius(string str);
double Mediana(int a[], int k);

int main(){
    vector<data> mokinys;
    string sk("T");
    while (sk !="N"){
        cout << "Jei norite prideti mokini rasykite: T, jei ne rasykite: N"<<endl;
        cin >> sk;
        sk = PavertimasDidziosiomisR(sk);
        if (sk=="N") break;
        else if (sk=="T") {
            mokinys.push_back(data());
            ivestis(mokinys);
        }
        else cout << "ivedete neteisinga reiksme" << endl;
    }
    isvestis(mokinys);

    mokinys.clear();
    return 0;
}
void ivestis(vector<data>& temp){
    cout << "Iveskite varda: "; cin >> temp.back().vardas;
    cout << "Iveskite pavarde: "; cin >> temp.back().pavarde;
    string n("T");
    bool ArIvede = false;
    cout << endl << "Veskite mokinio pazymius"<< endl <<
     "Pazymiai gali buti tik tarp 1-10 ir daugiausia galima ivesti 50 pazymiu"<<endl<<
     "Noredami uzbaigti pazymiu vedima irasykite: B"<<endl<<
    "** Jeigu norite, kad mokinio pazymius sugeneruotu atsitiktinius rasykite: A" <<endl;
    while(n!="B"){
        cin >> n;
        n = PavertimasDidziosiomisR(n);
        if (n == "B") break;
        else if (n == "A" and ArIvede == false){
            cout << "Kiek pazymiu norite sugeneruoti?" << endl;
            string sk ("-1");
            while (stoi(sk)<0 or stoi(sk)>50 or !Ar_tai_yra_skaicius(sk)){
                cin >> sk;
                if (!Ar_tai_yra_skaicius(sk) or stoi(sk)<0 or stoi(sk)>50)
                     cout << "Jus ivedete ne skaiciu arba negalima sugeneruoti tokio pasirenkto skaicio skaiciu, bandykite vel :)"<<endl;
                else {
                  temp.back().paz_sk = stoi(sk);
                  for (int i = 0; i <temp.back().paz_sk; i++){
                  temp.back().paz[i] = rand() % 10 + 1;
                  }
                  temp.back().egz = rand() % 10 + 1;
                  break;
                }
            }
            break;
        }
        else if (!Ar_tai_yra_skaicius(n)){
            cout << "Jus ivedete ne skaiciu, bandykite vel :)"<<endl;
        }
        else {
            int x = stoi(n);
            if (x > 10 or x<1) cout << "ivestas skaicius neatitinka kriterijaus"<<endl;
            else {
                temp.back().paz[temp.back().paz_sk] = x;
                temp.back().paz_sk++;
                if (temp.back().paz_sk == 50) break;
                ArIvede = true;
            }
        } 
    }
    if (ArIvede){
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
                    temp.back().egz = x;
                    break;
                }
            }
        }
    }
    if (temp.back().paz_sk != 0){
        int suma = 0; 
        for (int i=0; i<temp.back().paz_sk; i++) suma = suma + temp.back().paz[i];
        temp.back().vid = (suma/temp.back().paz_sk)*0.4+0.6*temp.back().egz;
        temp.back().med = Mediana(temp.back().paz, temp.back().paz_sk);   cout << temp.back().med <<" :: "<<temp.back().med<<endl;
    }
    else temp[temp.size()-1].vid = 0.6*temp[temp.size()-1].egz;
}
void isvestis(vector<data> t){
    string n("T");
    cout << "DUOMENU ISVEDIMAS"<<endl;
    cout << "Ka norite isvesti i ekrana kartu su mokinio vardu ir pavarde? :"<<endl;
    cout << "Iveskite V, jei norite matyti vidurki" <<endl;
    cout << "Iveskite M, jei norite matyti mediana" <<endl;
    cout << "Iveskite A, jei norite matyti vidurki ir mediana" <<endl;
    while(n != "V" or n!="M" or n != "A"){
        cin >> n; cout << n <<endl;
        n = PavertimasDidziosiomisR(n); cout << n <<endl;
        if (n == "V") {
            cout <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " <<endl;
            cout << "---------------------------------------------------------" <<endl;
            for (int i=0; i<t.size(); i++) {
            cout <<  left << setw(20) << t[i].vardas << setw(20) << t[i].pavarde;
            cout << setw(20) << fixed << setprecision(2) << t[i].vid << endl;
            }
            break;
        }
        else if (n == "M") {
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Med.) " <<endl;
            cout << "---------------------------------------------------------" <<endl;
            for (int i=0; i<t.size(); i++) {
            cout <<  left << setw(20) << t[i].vardas << setw(20) << t[i].pavarde;
            cout << setw(20) << fixed << setprecision(2) << t[i].med << endl;
            }
            break;
        }
        else if (n == "A") {
            cout <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " << setw(20) << "Galutinis (Med.) " <<endl;
            cout << "-----------------------------------------------------------------------------" <<endl;
            for (int i=0; i<t.size(); i++) {
            cout << left << setw(20) << t[i].vardas << setw(20) << t[i].pavarde;
            cout << setw(20) << fixed << setprecision(2) << t[i].vid << setw(20) << fixed << setprecision(2) << t[i].med << endl;
            }
            break;
        }
        else{
            cout << "Jus ivedete neteisinga simboli, bandykite vel :)"<<endl;
        }
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
double Mediana(int a[], int k){
    sort(a, a + k);
    if (k % 2 == 0){
        return (1.0*a[k/2] + 1.0*a[(k/2) - 1])/2;
      }
    else {
        return a[k/2];
    }
}
