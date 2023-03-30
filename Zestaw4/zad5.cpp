#include <iostream>

using namespace std;

class A
{
private:
    int liczba{0};

public:
    A(int num = 0) : liczba{num}
    {
    }

    A operator+(int num)
    {
        return liczba += num;
    }

    A operator-(int num)
    {
        return liczba -= num;
    }


    A operator++()//pre increment
    {
        return ++liczba;
    }

    A operator--()//pre decrement
    {
        const int temp=--liczba;
        return temp;
    }

    A operator++(int) //post increment
    {
        A temp{*this};
        ++(*this);
        return temp;
    }

    A operator--(int) //post decrement
    {
        A temp{*this};
        --(*this);
        return temp;
    }

    friend ostream &operator<<(ostream &out, const A &obj)
    {
        out << obj.liczba;
        return out;
    }
};

int main()
{
    A x{17};
    --x;
    x+3;
    ++x;
    ++++++x;
    ++++++++++++++++++++++++++++x;
    x--------------;
    cout << x << endl;
    // parzysta ilosc za lub przed obiektem, ale wartosc zmienia sie tylko o 1
}