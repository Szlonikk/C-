#include <iostream>
using namespace std;

int main(){

    int x,y,ramka;
    cout<<"Podaj wielkosc duzego kwadratu: "; cin>>x;
    cout<<"Podaj wielkosc malego kwadratu: "; cin>>y;
    if(x%2!=y%2){
        cout<<"\nKolidujace dane!";
        return 0;
    }
    ramka=(x-y)/2;
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i<ramka || x-i<=ramka || j<ramka || x-j<=ramka){
                cout<<"X";
            }
            else{
                cout<<" ";
            }
        
        }printf("\n");
    }

}