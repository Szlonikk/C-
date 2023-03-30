#include <iostream>
using namespace std;

class Klasa
{
public:
    void f() { 
        cout << "Funkcjia z klasy Klasa" << endl; 
        }
};

class SmartPrt
{
    Klasa *ptr{nullptr};

public:
    SmartPrt(Klasa *prt = nullptr) : ptr(prt) {}
    Klasa *operator->() { return ptr; }
    Klasa &operator*() { return *(operator->()); }
};

int main()
{
    Klasa obiekt;
    SmartPrt ptr = &obiekt;
    ptr->f();
    (*ptr).f();
}