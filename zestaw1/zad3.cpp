#include <iostream>
#include <cstring>
using namespace std;

bool palindrom(string zdanie){
    int i,j;
    for (i = 0, j = zdanie.length()-1; i < j; i++, j--)
    {
// pominiecie spacji
    if (zdanie[i] == ' ') i++;
    if (zdanie[j] == ' ') j--;
    if (toupper(zdanie[i])  != toupper(zdanie[j]))
    return 0;
    }
    return 1;
}

int main(){
    string t1;
    cout<<"Podaj tekst: "; getline(cin,t1);
    
    if(palindrom(t1)){
        cout<<"To jest palindrom!";
        
    }
    else
    cout<<"To nie jest palindrom";

}