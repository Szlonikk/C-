#include <iostream>
#include <random>
#include <cmath>
#include <string>

using namespace std;

// generowanie klucza RSA
int primeNumberGenetor()
{
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> distrib(2, 10000); // użycie genereatora
    int primeNumber = distrib(gen);
    int counter = 0;
    while (true)
    {
        for (int i = 2; i * i <= primeNumber; i++)
        {
            if (primeNumber % i == 0)
            {
                counter++;
                break;
            }
        }
        if (counter != 0)
        {
            primeNumber = distrib(gen);
            counter = 0;
        }
        else
        {
            return primeNumber;
        }
    }
}

int eulerFun(int p, int q)
{
    int fi = (p - 1) * (q - 1);
    return fi;
}

int nwd(int a, int b)
{
    return (a == 0) ? b : nwd(b % a, a);
}

int publicExponent(int fi)
{
    int e = 3;
    while (e < fi)
    {
        if (nwd(e, fi) == 1)
        {
            return e;
        }
        else
        {
            e++;
        }
    }
    return e;
}

int privateExponent(int e, int fi)
{
    int d;
    for (d = 1; d < fi; d++)
    {
        if ((d * e) % fi == 1)
        {
            return d;
        }
    }
    return d;
}

// szyfrowanie danych

int encryption(int input, int e, int n)
{
    unsigned long long potegaInputE = pow(input, e);
    int c = potegaInputE % n;
    return c;
}

// deszyfrowanie dancyh
int decryption(int c, int d, int n)
{
    unsigned long int potegaCD = pow(c, d);
    long long int t = potegaCD % n;
    return t;
}

int main()
{
    int input;
    cout << "Podaj dane do zaszyfrowanai: ";
    cin >> input;
    cout << "==============================================================" << endl;
    cout << "\t\t\tINPUT: " << input << endl;

    // generowanie klucza RSA
    int p = primeNumberGenetor();
    int q = primeNumberGenetor();
    int n = p * q;

    if (input > n)
    {
        cout << "Zla konfiguracja liczb input>n, sprobuj ponownie" << endl;
        return 0;
    }

    int fi = eulerFun(p, q);
    int e = publicExponent(fi);
    int d = privateExponent(e, fi);

    // szyfrowanie danych
    int c = encryption(input, e, n);

    // deszyfrowanie danych
    int t = decryption(c, d, n);

    // wypisanie danych niejawnych
    cout << "==============================================================" << endl;
    cout << "\t\t\tDANE NIEJAWNE: " << endl;
    cout << "==============================================================" << endl;

    cout << "[NIEJAWNE] RANDOM PRIME NUMBERS: " << p << "  " << q << endl;
    cout << "[NIEJAWNE] PUBLIC KEY: " << d << endl;
    cout << "[NIEJAWNE] ILOCZYN p*q: " << n << endl;

    cout << "=============================================================" << endl;
    cout << "\t\t\tDANE JAWNE: " << endl;
    cout << "=============================================================" << endl;

    cout << "PUBLIC KEY: " << e << endl;
    cout << "ILOCZYN p*q: " << n << endl;
    cout << "=============================================================" << endl;
    cout << "\t\t\tDANE ZASZYFROWANE: " << c << endl;

    cout << "=============================================================" << endl;
    cout << "\t\t\tWYNIK: " << t << endl;
    cout << "=============================================================" << endl;
}