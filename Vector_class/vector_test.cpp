#include <iostream>
#include "vector.h"
template<typename T>
void Print(const Vector<T>& v);
int main(){
    Vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    Print(v);
    std::cout << "v size: " << v.size() << std::endl;
    v.pop_back();
    std::cout << "v size: " << v.size() << std::endl;
    Print(v);
    v.at(0) = 'z';
    Print(v);
    std::cout << "v size: " << v.size() << std::endl;
    v.resize(1);
    std::cout << "v size: " << v.size() << std::endl;
    v.push_back('c');
    Print(v);
    v.erase(0);
    Print(v);
    v.push_back('b');
    v.push_back('d');
    std::cout << "v capasity: " << v.capacity() << std::endl;
    std::cout << "v size: " << v.size() << std::endl;
    Print(v);
    v.insert(1, 'g');
    std::cout << "v capasity: " << v.capacity() << std::endl;
    std::cout << "v size: " << v.size() << std::endl;
    Print(v);
    v.insert(1, 'g');
    std::cout << "v capasity: " << v.capacity() << std::endl;
    std::cout << "v size: " << v.size() << std::endl;
    Print(v);
    v.shrink_to_fit();
    std::cout << "v capasity: " << v.capacity() << std::endl;
    std::cout << "v size: " << v.size() << std::endl;
    v.emplace(2, 'e');
    Print(v);
    v.emplace_back('z');
    Print(v);
    std::cout << "v capasity: " << v.capacity() << std::endl;
    std::cout << "v size: " << v.size() << std::endl;
    v.erase(2);
    std::cout << "v capasity: " << v.capacity() << std::endl;
    std::cout << "v size: " << v.size() << std::endl;
    v.~Vector();
    Print(v);
    if(v.empty()) std::cout<<"tuscias";

    return 0;
}
template<typename T>
void Print(const Vector<T>& v){
    for(int i = 0; i<v.size(); i++){
        std::cout << v[i] << std::endl;
    }
    std::cout << "---------------" << std::endl;
}