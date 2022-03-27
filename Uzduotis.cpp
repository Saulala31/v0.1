#include "Funkcijos.h"
#include "Timer.h"


int main(){
    vector<data> mokinys;
    vector<data> vargsiukai;
    vector<data> galvociai;
    string sk("T");
    int kiekisStud, pazsk, NrStru = 0, Studentai = 100, nr = 0;
    bool Generavimas = false;
    while (sk !="N"){
        cout << "Jei norite prideti mokini rasykite: T, jei ne rasykite: N"<<endl;
        cout << "Duomenys nuskaitymui is failo rasykite: A" <<endl;
        cout << "Failu generavimui rasykite: G"<<endl;
        cin >> sk;
        sk = PavertimasDidziosiomisR(sk);
        if (sk == "N") break;
        else if (sk == "T") {
            mokinys.push_back(data());
            ivestis(mokinys);
        }
        else if (sk == "A"){
            ifstream df ("kursiokai.txt");
                try {
                    if (df){

                        }
                    else {
                        throw 505;
                        }
                    }
                catch (...)
                {
                    cout << "Sukurkite studentu duomenu faila pavadinimu: kursiokai.txt";
                    return 1;
                }
            nuskaitymas(mokinys, df);
            df.close();
            break;
        }
        else if (sk == "G"){
            Generavimas = true;
            cout <<"Ar sugeneruoti nauja faila? Y/N";
            while (Generavimas){
                cin >> sk;
                sk = PavertimasDidziosiomisR(sk);
                if (sk == "N"){
                    cout << "Kokio kiekio studentu faila apdoroti?";
                    cin >> kiekisStud;
                    cout << endl;
                    Timer t; // paleisti
                    string failas = "Test" + to_string(kiekisStud)+".txt";
                    ifstream tt (failas);
                    nuskaitymas (mokinys, tt);
                    tt.close();
                    skirstymas(vargsiukai, galvociai, mokinys, kiekisStud);
                    FailuIsvedimas(vargsiukai, galvociai);
                    cout << endl << kiekisStud << " Visos programos veikimas uztruko: " << t.elapsed() << " s\n";
                    break;
                }
                else if(sk =="Y") {
                    cout << "Po kiek pazymiu tures studentai?";
                    cin >> pazsk;
                    for (int i=100; i<=100000; i=i*10){
                        FailuGeneravimas( i, pazsk);
                        NrStru++;
                    }

                    Timer t; // paleisti
                    cout << "Kokio kiekio studentu faila apdoroti?";
                    cin >> kiekisStud;
                    cout << endl;
                    string failas = "Test" + to_string(kiekisStud)+".txt";
                    ifstream tt (failas);
                    nuskaitymas(mokinys, tt);
                    tt.close();
                    skirstymas(vargsiukai, galvociai, mokinys, kiekisStud);
                    FailuIsvedimas(vargsiukai, galvociai);

                    cout << endl << kiekisStud << " Visos programos veikimas uztruko: " << t.elapsed() << " s\n";
                break;
                }
                else cout << "ivedete neteisinga reiksme" << endl;
            }
                break;
        }
        else cout << "ivedete neteisinga reiksme" << endl;
    }
    if (!mokinys.empty() and !Generavimas) isvestis(mokinys);

    mokinys.clear();
    return 0;
}
