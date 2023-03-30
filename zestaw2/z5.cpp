#include <iostream>

using namespace std;

int main(){
    int arab,i=0;
    int wartosc[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string wynik="";
    string znaki[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    cout<<"Podaj wartosc z przedzialu 1-3999: "; cin>>arab;
    while(arab>0 && i<13){
        if(arab-wartosc[i]>=0){
            wynik=wynik+znaki[i];
            arab=arab-wartosc[i];
        }
        else{
            i++;
        }

    }
    cout<<wynik<<endl;
}