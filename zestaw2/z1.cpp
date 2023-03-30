#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(){
    fstream plik;
    string text,linia;
    int n;
    plik.open("tekst.txt",ios::in);
    if(plik.good()==false){
        cout<<"Blad pliku!";
        exit(1);
    }
    while(!plik.eof()){
        getline(plik,linia);
        text=text+linia;
    }
    cout<<"Podaj do ilu znakow wyrownac: "; 
    cin>>n;
    for(int i=0;i<text.size();++i){
        cout<<text[i];
        if(i%n==0 && i!=0){
            printf("\n");
        }
    }
    cout<<text[0];
    plik.close();
}