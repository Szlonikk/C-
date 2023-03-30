#include <iostream>
#include <conio.h>
using namespace std;
long long int tab[1000]={};
long long int fibIT(long long int n,long long int najw)
{    
     long long i;
    
     for( i=najw+1;i<=n;i++)
     {
            tab[i]=tab[i-1]+tab[i-2];
     } 
     return tab[n];    
}

int main(){
    long long int najwiekszy=1,n;
    char ch='a';
    tab[0]=0;
    tab[1]=1;

    while(ch!='n')
    {
        cout<<"\nPodaj ktory wyraz ciagu wypisac: ";
        cin>>n;
        if(n<=najwiekszy)
            cout<<tab[n];
        else
            cout<<fibIT( n, najwiekszy);
        if(najwiekszy<n) najwiekszy=n;
        cout<<"\nNacisnij N aby przerwac lub cokolwiek innego by kontynowac "; ch=getche();
    }

}