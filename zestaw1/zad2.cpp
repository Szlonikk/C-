#include <iostream>
#include <cstring>
using namespace std;


int main(){
    char tablica[1000];
    char tablica2[1000];
    cout<<"Podaj pierwszy ciag znakow do porownania: ";
    cin.getline(tablica,999);
    cout<<"\nPodaj drugi ciag znakow: ";
    cin.getline(tablica2,999);

    if( stricmp( tablica, tablica2 ) == 0 )
         printf( "Badane lancuchy znakow sa identyczne.\n" );
    else
         printf( "Badane lancuchy znakow nie sa identyczne.\n" );
}