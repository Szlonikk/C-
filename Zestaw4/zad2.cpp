#include <iostream>
#include <cstring>
using namespace std;

class Konwerter
{
private:
    unsigned long skladowa{};

public:
    Konwerter() : skladowa(0) {}

    void operator()(string s)
    {
        skladowa = 0;
        for (const char &i : s)
            skladowa += i;
    }

    void operator()(char c)
    {
        skladowa = c;
    }

    void operator()(const char *s)
    {
        skladowa = 0;
        int i = 0;
        while (i !=strlen(s))
        {
            skladowa +=(s[i]);
            i++;
        }
    }

    friend ostream &operator<<(ostream &os, const Konwerter &obiekt)
    {
        os << obiekt.skladowa;
        return os;
    }

    friend istream &operator>>(istream &is, Konwerter &obiekt)
    {
        is >> obiekt.skladowa;
        return is;
    }
};

int main()
{
    Konwerter conv;
    cout << "liczba 6: " << endl;
    conv('6');
    cout << "char : " << conv << endl;
     cout << "liczba 641: " << endl;
    conv("641");
    cout << "const char : " << conv << endl;
     cout << "liczba 12345: " << endl;
    string str("12345");
    conv(str);
    cout << "string : " << conv << endl;
}