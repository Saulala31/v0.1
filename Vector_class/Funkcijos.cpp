#include "Timer.h"
#include "Studentas.h"
void ivestis(vector<data>& temp){
    string v, p;
    cout << "Iveskite varda: "; cin >> v; temp.back().setVardas(v);
    cout << "Iveskite pavarde: "; cin >> p;  temp.back().setPavarde(p);
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
                  temp.back().setPaz_Sk(stoi(sk));
                  srand(time(NULL));
                  int rand_sk;
                  for (int i = 0; i <temp.back().getPaz_Sk(); i++){
                        do {
                        rand_sk = rand();
                        } while ( rand_sk > (RAND_MAX - (RAND_MAX % 100)) );
                  temp.back().NewPaz(rand_sk % 10 + 1);
                  }
                        do {
                        rand_sk = rand();
                        } while ( rand_sk > (RAND_MAX - (RAND_MAX % 100)) );
                  temp.back().setegz(rand_sk % 10 + 1);
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
                temp.back().NewPaz(x);
                temp.back().setPaz_Sk(temp.back().getPaz_Sk()+1);
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
                    temp.back().setegz(x);
                    break;
                }
            }
        }
    }
    if (temp.back().getPaz_Sk() != 0){
        int suma = 0; 
        for (int i=0; i<temp.back().getPaz_Sk(); i++) suma = suma + temp.back().getPaz()[i];
        temp.back().setvid((suma/temp.back().getPaz_Sk())*0.4+0.6*temp.back().getegz());
        temp.back().setmed(Mediana(temp.back().getPaz()));
    }
    else temp.back().setvid(0.6*temp.back().getegz());
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
    string cell, line, p;
    const int c3 = nd_sk +2;
    while(std::getline(df, line)){
    lineStream.clear();
    lineStream.str(line);
    int suma = 0;
    int pazimys;
    while(std::getline(lineStream, cell, ' ' ))
                {
                    if(cell != ""){
                            temp.back().setVardas(cell);
                            lineStream >> p; temp.back().setPavarde(p);
                            for (int i=0; i<nd_sk; i++){
                                lineStream >> pazimys;
                                temp.back().setpaz_suma(temp.back().getpaz_suma() + pazimys);
                                temp.back().NewPaz(pazimys);
                            }
                            lineStream >> pazimys;
                            temp.back().setegz(pazimys);
                    }
                }
    if (!df.eof( ))  temp.push_back(data());
    }
    cout << temp.size()-1 << " Nuskaitymas uztruko: " << t.elapsed() << " s\n";
    for (int i= 0; i<=temp.size(); i++){
        if (temp[i].getpaz_suma() != 0){
            temp[i].setvid((temp[i].getpaz_suma()/nd_sk)*0.4+0.6*temp[i].getegz());
            temp[i].setmed(Mediana(temp[i].getPaz()));
        }
        else temp[i].setvid(0.6*temp[i].getegz());
    }

    Timer sortin;
    sort(temp.begin(), temp.end(), palyginimas);
    cout << temp.size()-1 << " Studentu rykiavimas uztruko: " << sortin.elapsed() << " s\n";
}
bool palyginimas(const data& a, const data& b)
{
    return a.vardas() < b.vardas();
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
                sakinys = zodziu_sujungimas(elem.vardas(), elem.pavarde());
                RF << sakinys << setw(20) << fixed << setprecision(2) << elem.getvid() << endl;
            }
            break;
        }
        else if (n == "M") {
            RF << left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Med.) " <<endl;
            RF << string (60, '-') <<endl;
            for (const auto& elem : t) {
                sakinys = zodziu_sujungimas(elem.vardas(), elem.pavarde());
                RF << sakinys << setw(20) << fixed << setprecision(2) << elem.getmed() << endl;
            }
            break;
        }
        else if (n == "A") {
            RF <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " << setw(20) << "Galutinis (Med.) " <<endl;
            RF << string (80, '-') <<endl;
            for (const auto& elem : t){
                sakinys = zodziu_sujungimas(elem.vardas(), elem.pavarde());
            RF << sakinys << setw(20) << fixed << setprecision(2) << elem.getvid() << setw(20) << elem.getmed() << endl;
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
                sakinys = zodziu_sujungimas(elem.vardas(), elem.pavarde());
                cout << sakinys << setw(20) << fixed << setprecision(2) << elem.getvid() << endl;
            }
            break;
        }
        else if (n == "M") {
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Med.) " <<endl;
            cout << string (60, '-') <<endl;
            for (const auto& elem : t) {
                sakinys = zodziu_sujungimas(elem.vardas(), elem.pavarde());
                cout << sakinys << setw(20) << fixed << setprecision(2) << elem.getmed() << endl;
            }
            break;
        }
        else if (n == "A") {
            cout <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " << setw(20) << "Galutinis (Med.) " <<endl;
            cout << string (80, '-') <<endl;
            string skaicius;
            for (const auto& elem : t){
                sakinys = zodziu_sujungimas(elem.vardas(), elem.pavarde());
                cout << sakinys << setw(20) << fixed << setprecision(2) << elem.getvid() << setw(20) << fixed << setprecision(2) << elem.getmed() << endl;
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
        if (temp[i].getvid() < 5.0) {
           var.push_back(temp[i]);
        }
    }
    cout << moksk << " Vargsiuku studentu rusiavimas uztruko: " << hvar.elapsed() << " s\n";
    Timer hgal;
    for (int i=1; i<=moksk; i++){
        if (temp[i].getvid() >= 5.0){
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
            varg << elem.Toline() <<endl;
        }
    varg.close();
    
    ofstream galv;
    galv.open ("Galvociai.txt");
    galv <<  left << setw(20) << "Vardas" << setw(20) << "Pavarde "<< setw(20) << "Galutinis (Vid.) " << endl;
    galv << string (80, '-') <<endl;
    for (const auto& elem : gal){
            galv << elem.Toline() <<endl;
        }

    galv.close();
    cout << gal.size()+var.size() << " Failu isvedimas uztruko: " << t.elapsed() << " s\n";
    gal.clear();
    var.clear();
}
