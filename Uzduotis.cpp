#include <iostream>
#include <string>
#include <iomanip>

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

int main(){
    data *root = NULL;
    int sk = 1, k=0;
    cout << "Mokiniu pridejimas"<<endl;
    while (sk !=0){
        cout << "jei norite prideti mokini rasykite: 1, jei ne rasykite: 0"<<endl;
        cin >> sk;
            if (sk== 0) break;
            else add_mok(*&root);
    }

    isvestis(root);

    delete[] root;

    return 0;
}
void ivestis(data& temp){
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    int n = 1;
    cout << "Veskite mokinio pazymius. Noredami uzbaigti pazymiu vedima irasykite: 0"<<endl; 
    while(n!=0){
        cin >> n;
        if (n==0) break;
        else {
            temp.paz[temp.paz_sk] = n;
            temp.paz_sk++;
        }
    }
    cout << "iveskite egzamino pazymi: "; cin >> temp.egz;
}   

void isvestis(data *root) {
  data *t = root;
  while (t) {
    cout << std::setw(20) << t->vardas << std::setw(20) << t->pavarde;
    for (int i = 0; i<t->paz_sk; i++) cout << std::setw(10) << t->paz[i];
    cout << std::setw(10) << t->egz << std::endl;
    t = t->next;
  }
  cout << endl;
}

void add_mok(data *&root) {
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