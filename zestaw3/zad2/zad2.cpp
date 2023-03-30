#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
    {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}

class BigInt
{
public:
    string a;

public:
    BigInt(string s) : a{""}
    {
        a = s;
    }
    BigInt &operator=(const BigInt s)
    {
        if (this->a != s.a)
            this->a = s.a;
        return *this;
    }
    string Add(BigInt x)
    {

        string str = ""; // wynik

        // trzymamy dlugosc
        int n1 = a.length(), n2 = x.a.length();

        // odwrocenie stringow
        reverse(a.begin(), a.end());
        reverse(x.a.begin(), x.a.end());

        int carry = 0;
        for (int i = 0; i < n1; i++)
        {

            int sum = ((a[i] - '0') + (x.a[i] - '0') + carry);
            str.push_back(sum % 10 + '0');

            // licznie przeniesienia
            carry = sum / 10;
        }

        // dodaj brakujace cyfry wiekszej liczby
        for (int i = n1; i < n2; i++)
        {
            int sum = ((x.a[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        // dodaj brakujace przeniesienie
        if (carry)
            str.push_back(carry + '0');

        // odwrocenie rezultatu
        reverse(str.begin(), str.end());

        return str;
    }

    string Diff(BigInt str2)
    {

        // wynik
        string str = "";

        // obliczenie dlugosci wyrazen
        int n1 = a.length(), n2 = str2.a.length();
        int diff = n1 - n2;

        // przeniesienie
        int carry = 0;

                for (int i = n2 - 1; i >= 0; i--)
        {

            int sub = ((a[i + diff] - '0') - (str2.a[i] - '0') - carry);
            if (sub < 0)
            {
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }

        // odejmij pozostale cyfry
        for (int i = n1 - n2 - 1; i >= 0; i--)
        {
            if (a[i] == '0' && carry)
            {
                str.push_back('9');
                continue;
            }
            int sub = ((a[i] - '0') - carry);
            if (i > 0 || sub > 0) // usuń poprzedzające zera
                str.push_back(sub + '0');
            carry = 0;
        }

        // reverse resultant string
        reverse(str.begin(), str.end());

        return str;
    }
};

int main()
{
    BigInt a{""}, b{""}, c{""}, d{""};

    cout << "Podaj wartosc 1 liczby: ";
    cin >> a.a;

    cout << "Podaj wartosc 2 liczby: ";
    cin >> b.a;

    if (a.a.length() <= b.a.length())
        cout << "\n"
             << a.Add(b) << endl;
    else
        cout << "\n"
             << b.Add(a) << endl;

    cout << "\nOdejmowanie wiekszej od mniejszej\n";
    cout << "Podaj wartosc 1 liczby: ";
    cin >> c.a;

    cout << "Podaj wartosc 2 liczby: ";
    cin >> d.a;
    if (isSmaller(c.a, d.a))
        cout << "\n"
             << d.Diff(c) << endl;
    else
        cout << "\n"
             << c.Diff(d) << endl;

    return 0;
}