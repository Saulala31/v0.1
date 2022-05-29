#include <iostream>
#include <vector>
#include "vector.h"
#include "Timer.h"
int main(){
unsigned int sz = 65;  // 100000, 1000000, 10000000, 100000000
Timer t;
std::vector<int> v1;
for (int i = 1; i <= sz; ++i)
  v1.push_back(i);
std::cout << " vector uztruko: " << t.elapsed() << " s\n";
std::cout << v1.capacity()<<std::endl;
Timer t2;
Vector<int> v2;
for (int i = 1; i <= sz; ++i)
  v2.push_back(i);
std::cout << " Mano Vector uztruko: " << t2.elapsed() << " s\n";



/// capacity() == size()

int k1 = 0, h1 = 0;
std::vector<int> k;
for (int i = 1; i <= sz; ++i){
  k.push_back(i);
    if (k.capacity() == k.size())
        k1++;
}


Vector<int> h;
for (int i = 1; i <= sz; ++i){
  h.push_back(i);
  if (h.capacity() == h.size())
        h1++;
}

std::cout<< " k1: " << k1 <<" h1: "<< h1;

}