#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <list>
using namespace std;

int main(){
    list<char> lista{'a', 'c', 'b', 'd','f', 'e', 'h', 'g'};

    auto sortowanie=[lista](const auto& a, const auto& b){
        auto iter=lista.begin();
    while(*iter!=a){iter++;}
    if (*(iter++)==b) return true; else return false;};

    using set_z_lambda = set<char, decltype(sortowanie)>;
    set_z_lambda  mySet ({'a', 'a' , 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'},sortowanie);
    

    for (auto c:mySet) cout << c;
}


  