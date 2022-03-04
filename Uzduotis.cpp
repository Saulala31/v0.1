#include "Funkcijos.cpp"

int main(){
    vector<data> mokinys;
    string sk("T");
    while (sk !="N"){
        cout << "Jei norite prideti mokini rasykite: T, jei ne rasykite: N"<<endl;
        cout << "Jei norite, kad duomenys butu nuskaityti is failo rasykite: A" <<endl;
        cin >> sk;
        sk = PavertimasDidziosiomisR(sk);
        if (sk == "N") break;
        else if (sk == "T") {
            mokinys.push_back(data());
            ivestis(mokinys);
        }
        else if (sk == "A"){
            nuskaitymas(mokinys);
            break;
        }
        else cout << "ivedete neteisinga reiksme" << endl;
    }
    if (!mokinys.empty()) isvestis(mokinys);

    mokinys.clear();
    return 0;
}
