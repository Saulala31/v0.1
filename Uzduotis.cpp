#include "Funkcijos.h"

int main(){
    vector<data> mokinys;
    string sk("T");
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
                FailuGeneravimas();
                break;
        }
        else cout << "ivedete neteisinga reiksme" << endl;
    }
    if (!mokinys.empty()) isvestis(mokinys);

    mokinys.clear();
    return 0;
}
