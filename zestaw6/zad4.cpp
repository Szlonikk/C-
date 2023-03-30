#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;
int main(){

    vector<int> v(14);
    iota(v.begin(),v.end(),0);
 
    auto sklej = [](string a, int b) {
                         return move(a) + '-' + to_string(b);};
 
    string s =accumulate(next(v.begin()), v.end(),to_string(v[0]), sklej);
    
    cout<<"sklejony napis "<<s<<endl;
    return 0;
}