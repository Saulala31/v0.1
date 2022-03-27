#include "Funkcijos.h"
#include "Timer.h"
void ivestis(vector<data>& temp){
    cout << "Iveskite varda: "; cin >> temp.back().vardas;
    cout << "Iveskite pavarde: "; cin >> temp.back().pavarde;
    string n("T");
    bool ArIvede = false;
    cout << endl << "Veskite mokinio pazymius"<< endl <<
     "Pazymiai gali buti tik tarp 1-10"<<endl<<
     "Noredami uzbaigti pazymiu vedima irasykite: B"<<endl<<
    "** Jeigu norite, kad mokinio pazymius sugeneruotu atsitiktinius rasykite: A" <<endl;
    while(n!="B"){
        cin >> n;
        n = PavertimasDidziosiomisR(n);
        if (n == "B") break;
        else if (n == "A" and ArIvede == false){
            cout << "Kiek pazymiu norite sugeneruoti?" << endl;
            string sk ("-1");
            while (stoi(sk)<0 or !Ar_tai_yra_skaicius(sk)){
                cin >> sk;
                if (!Ar_tai_yra_skaicius(sk) or stoi(sk)<0)
                     cout << "Jus ivedete ne skaiciu arba negalima sugeneruoti tokio pasirenkto skaicio skaiciu, bandykite vel :)"<<endl;
                else {
                  temp.back().paz_sk = stoi(sk);
                  srand(time(NULL));
                  int rand_sk;
                  for (int i = 0; i <temp.back().paz_sk; i++){
                        do {
                        rand_sk = rand();
                        } while ( rand_sk > (RAND_MAX - (RAND_MAX % 100)) );
                  temp.back().paz.push_back(rand_sk % 10 + 1); cout << " PAZ: " << temp.back().paz.back() << endl;
                  }
                        do {
                        rand_sk = rand();
                        } while ( rand_sk > (RAND_MAX - (RAND_MAX % 100)) );
                  temp.back().egz = rand_sk % 10 + 1; cout << "EGZ:  " << temp.back().egz << endl;
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
                temp.back().paz.push_back(x);
                temp.back().paz_sk++;
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
        temp.back().med = Mediana(temp.back().paz);
    }
    else temp.back().vid = 0.6*temp.back().egz;
}
void nuskaitymas(vector <data> &temp, ifstream& df){
  string zodis;
  int nd_sk = 0, pazimys;
  Timer t; // paleisti
  while (zodis != "Egz."){
       df >> zodis;
       if (zodis == "Egz.") break;
       else if (zodis.substr(0, 2) == "ND"){
            nd_sk++;
       }
  }
    std::stringstream   lineStream;
    string line;
    string cell;
    const int c3 = nd_sk +2;
    while(std::getline(df, line)){
    lineStream.clear();
    lineStream.str(line);
    int suma = 0;
    int pazimys;
    while(std::getline(lineStream, cell, ' ' ))
                {
                    if(cell != ""){
                            temp.back().vardas = cell;
                            lineStream >> temp.back().pavarde;
                            for (int i=0; i<nd_sk; i++){
                                lineStream >> pazimys;
                                temp.back().paz_suma +=pazimys;
                                temp.back().paz.push_back(pazimys);
                            }
                            lineStream >> pazimys;
                            temp.back().egz = pazimys;
                    }
                }
    if (!df.eof( ))  temp.push_back(data());
    }
    cout << temp.size()-1 << " Nuskaitymas uztruko: " << t.elapsed() << " s\n";
    for (int i= 0; i<=temp.size(); i++){
        if (temp[i].paz_suma != 0){
            temp[i].vid = (temp[i].paz_suma/nd_sk)*0.4+0.6*temp[i].egz;
            temp[i].med = Mediana(temp[i].paz);
        }
        else temp[i].vid = 0.6*temp[i].egz;
    }

    Timer sortin;
    sort(temp.begin(), temp.end(), palyginimas);
    cout << temp.size()-1 << " Studentu rykiavimas uztruko: " << sortin.elapsed() << " s\n";
}
bool palyginimas(const data& a, const data& b)
{
    return a.vardas < b.vardas;
}
bool Ar_tai_yra_skaicius(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
      return false;
      return true;
}
double Mediana(vector <int> a){
    sort(a.begin(), a.end());
    if (a.size() % 2 == 0){
        return (1.0*a[a.size()/2] + 1.0*a[(a.size()/2) - 1])/2;
      }
    else {
        return a[a.size()/2];
    }
}
void isvestis(vector<data> t){
    string n("T"), f("T") , sakinys;
    bool failas = false;
    cout << "DUOMENU ISVEDIMAS"<<endl;
    cout << "Ka norite isvesti i ekrana kartu su mokinio vardu ir pavarde? :"<<endl;
    cout << "Iveskite V, jei norite matyti vidurki" <<endl;
    cout << "Iveskite M, jei norite matyti mediana" <<endl;
    cout << "Iveskite A, jei norite matyti vidurki ir mediana" <<endl;

    while(n != "V" or n!="M" or n != "A"){
        cin >> n;
        n = PavertimasDidziosiomisR(n);

        cout << "Ar norite duomenis isvesti i faila? Y/N"<<endl;
        while (n != "Y" or n!="N"){
            cin >> f;
            f = PavertimasDidziosiomisR(f);
            if (f == "Y"){
                failas = true;
                break;
            }
            else if (f == "N"){
                failas = false;
                break;
            }
            else {
                cout << "Jus ivedete neteisinga simboli, bandykite vel :)"<<endl;
            }
        }
        if (failas){
            ofstream RF;
            RF.open ("Rezultatai.txt");
            if (n == "V") {
            RF <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " <<endl;
            RF << string (60, '-') <<endl;
            for (const auto& elem : t) {
                sakinys = zodziu_sujungimas(elem.vardas, elem.pavarde);
                RF << sakinys << setw(20) << fixed << setprecision(2) << elem.vid << endl;
            }
            break;
        }
        else if (n == "M") {
            RF << left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Med.) " <<endl;
            RF << string (60, '-') <<endl;
            for (const auto& elem : t) {
                sakinys = zodziu_sujungimas(elem.vardas, elem.pavarde);
                RF << sakinys << setw(20) << fixed << setprecision(2) << elem.med << endl;
            }
            break;
        }
        else if (n == "A") {
            RF <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " << setw(20) << "Galutinis (Med.) " <<endl;
            RF << string (80, '-') <<endl;
            for (const auto& elem : t){
                sakinys = zodziu_sujungimas(elem.vardas, elem.pavarde);
            RF << sakinys << setw(20) << fixed << setprecision(2) << elem.vid << setw(20) << elem.med << endl;
            }
            break;
        }
            RF.close();

        }
        else{
        if (n == "V") {
            cout <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " <<endl;
            cout << string (60, '-') <<endl;
            for (const auto& elem : t) {
                sakinys = zodziu_sujungimas(elem.vardas, elem.pavarde);
                cout << sakinys << setw(20) << fixed << setprecision(2) << elem.vid << endl;
            }
            break;
        }
        else if (n == "M") {
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Med.) " <<endl;
            cout << string (60, '-') <<endl;
            for (const auto& elem : t) {
                sakinys = zodziu_sujungimas(elem.vardas, elem.pavarde);
                cout << sakinys << setw(20) << fixed << setprecision(2) << elem.med << endl;
            }
            break;
        }
        else if (n == "A") {
            cout <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " << setw(20) << "Galutinis (Med.) " <<endl;
            cout << string (80, '-') <<endl;
            string skaicius;
            for (const auto& elem : t){
                sakinys = zodziu_sujungimas(elem.vardas, elem.pavarde);
                cout << sakinys << setw(20) << fixed << setprecision(2) << elem.vid << setw(20) << fixed << setprecision(2) << elem.med << endl;
            }
            break;
        }
        else{
            cout << "Jus ivedete neteisinga simboli, bandykite vel :)"<<endl;
        }
        }
    }
}
string zodziu_sujungimas(string v, string v2){
    string z = "";
            z += v;
        for (int i=0; i<20-v.length(); i++) z += " ";
            z += v2;
        for (int i=0; i<20-v2.length(); i++) z += " ";
    return z;
}
string PavertimasDidziosiomisR(string s){
    transform(s.begin(), s.end(), s.begin(),
               [](unsigned char c){ return toupper(c); });
    return s;
}
void FailuGeneravimas( int kiek, int pazsk){
    Timer t; // paleisti
    ofstream gen;
    string failas = "Test"+to_string(kiek)+".txt";
    gen.open (failas);
    int skaicius, rand_sk; 
    string vard = "Vardas", pava = "Pavarde", sakinys;
    gen << zodziu_sujungimas(vard, pava);
    for (int i=1; i<=pazsk; i++) gen << "ND" << i << " ";
    gen << "Egz." <<endl;
    srand(time(NULL));
    for (int i=1; i<=kiek; i++){
        sakinys = "";
        sakinys = sakinys + zodziu_sujungimas(vard + to_string(i), pava + to_string(i));
        for (int j=0; j<=pazsk; j++){
            do {
                rand_sk = rand();
                } while ( rand_sk > (RAND_MAX - (RAND_MAX % 100)) );
                        skaicius = rand_sk % 10 + 1;
            sakinys = sakinys + to_string(skaicius) + "   ";
        }
        gen << sakinys << endl;
    }
    gen.close();
    cout << kiek << " failo sukurimas uztruko: " << t.elapsed() << " s\n";

}
void skirstymas(vector <data> & var, vector <data> & gal, vector <data> temp, int moksk){
    Timer hvar;
    for (int i=1; i<=moksk; i++){
        if (temp[i].vid < 5.0) {
           var.push_back(temp[i]);
        }
    }
    cout << moksk << " Vargsiuku studentu rusiavimas uztruko: " << hvar.elapsed() << " s\n";
    Timer hgal;
    for (int i=1; i<=moksk; i++){
        if (temp[i].vid >= 5.0){
            gal.push_back(temp[i]);
        }
    }
    cout << moksk << " Galvociu studentu rusiavimas uztruko: " << hgal.elapsed() << " s\n";
}
void FailuIsvedimas(vector <data> & var, vector <data> & gal){
    Timer t; // paleisti

    ofstream varg;
    varg.open ("Vargsiukai.txt");
    varg <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " << endl;
    varg << string (80, '-') <<endl;
    string sakinys;
    for (const auto& elem : var){
            sakinys = "";
            sakinys = zodziu_sujungimas(elem.vardas, elem.pavarde);
            varg << sakinys << setw(20) << fixed << setprecision(2) << elem.vid <<endl;
        }

    varg.close();
    ofstream galv;
    galv.open ("Galvociai.txt");
    galv <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " << endl;
    galv << string (80, '-') <<endl;
    for (const auto& elem : gal){
            sakinys = "";
            sakinys = zodziu_sujungimas(elem.vardas, elem.pavarde);
            galv << sakinys << setw(20) << fixed << setprecision(2) << elem.vid <<endl;
        }

    galv.close();

    cout << gal.size()+var.size() << " Failu isvedimas uztruko: " << t.elapsed() << " s\n";
}
