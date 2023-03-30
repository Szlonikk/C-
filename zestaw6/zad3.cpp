#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main(){
    map<int,string> mis{{0,"zero"},{1,"jeden"},{2, "dwa"},{3,"trzy"},{4,"cztery"},{5,"piec"},{6,"szesc"},{7,"siedem"},{8,"osiem"},{9,"dziewiec"}};
    vector<int> v(10);
    iota(v.begin(),v.end(),0);
    transform(v.begin(),v.end(),ostream_iterator<string>(cout," "), [mis](int i){return mis.at(i);});

    return 0;
}