#include <iostream>
#include <conio.h>
using namespace std;

int fibIT(int n)
{    
     long long a = 0, b = 1;
  
     for(int i=0;i<n;i++)
     {
            b += a; 
            a = b-a; 
     } 
     return b;    
}
int fib(int n)
{
	if(n<3)
		return 1;
	
	return fib(n-2)+fib(n-1);
}
int main(){
    char ch;
    unsigned long long k = 80;
    cout<<"Ile kolejnych wartosci ciagu fibo wyswietlic?: "; cin>>k;
    cout<<"Liczyc sposobem rekurencyjnym (nacisnij R) czy iteracyjnym (nacisnij I)";
    ch=getche();
    if(ch='r')
    
    
    for (unsigned long long i=1; i<=k; ++i) 
        cout << fib(i) << endl;
    else if(ch='i')
        for (unsigned long long i=1; i<=k; ++i) 
        cout << fibIT(i) << endl;
    else
    cout<<"Nie ma takiej metdoy";
}
    