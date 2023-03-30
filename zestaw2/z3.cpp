#include <initializer_list>
#include <cstdio>
#include <iostream>

using namespace std;

auto fun(const initializer_list<int> &lista)
{
    int suma = 0;
    for (auto i = lista.begin(); i != lista.end(); ++i)
    {
        suma += *i;
    }
    return suma;
}

int main()
{
    auto arg = {3,5,7,8};
    
    cout << fun(arg) << endl;
}