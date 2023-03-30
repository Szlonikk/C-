#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <string>
using namespace std;
int ktore_wypisanie=0;


vector<int> vec(100);

void wypisz()
{
    cout <<++ktore_wypisanie<<"."<< "liczby: ";
    for (int i = 0; i < 100; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl<<endl;
}


// struct sortowanie {
//     sortowanie(int val,int val2) : x{val},y{val2} { }
//     bool operator()() const { return y > x; }
//     private:
//         int x;
//         int y;
// };

int main()
{

    iota(vec.begin(), vec.end(), 1);

    auto rng = default_random_engine{};
    shuffle(begin(vec), end(vec), rng);

    wypisz();

    sort(vec.begin(), vec.end(), greater<int>());

    wypisz();

    shuffle(begin(vec), end(vec), rng);

    

    sort(begin(vec), end(vec), [](int a, int b) { return to_string(a) < to_string(b); });

    wypisz();

    
}
