#include <iostream>
#include <string>
using namespace std;

class TString{
    private:
    string a;
    public:
    TString(string s): a{""}{
        a=s;
        #ifdef DEBUG
    cout << "TString konstruktor " << a <<endl;
    #endif
    };
    TString(const TString& s){
        a=s.a;
        #ifdef DEBUG
    cout << "TString konstruktor kopiujacy " << a <<endl;
    #endif
    }
    TString(TString&& s) : a{s.a} {
    a="";

    #ifdef DEBUG
        cout << "TString konsruktor przenosacy " << a <<endl;
    #endif
    }

    ~TString(){
         #ifdef DEBUG
        cout << "TString destruktor " << a <<endl;
        
    #endif
    };
    
    TString& operator=(const TString& s) {
    if (this!=&s) {
       a=s.a;
    }
    #ifdef DEBUG
        cout << "TString cp operator= " << a <<endl;
    #endif
    return *this;
}   
    TString& operator=(TString&& s) {
    if (this!=&s) {
        a=s.a;
        s.a="";
    }
    #ifdef DEBUG
        cout << "TString mv operator= " << a << endl;
    #endif
    return *this;
}
   TString& operator=(string s) {
    if (this->a!=s) {
        a=s;
        
    }
    #ifdef DEBUG
        cout << "TString mv operator= " << a << endl;
    #endif
    return *this;
}
};


int main(){
    TString a{"ABC"};
    TString b{a},c{"lol"};
    
    
    a=c;
    a="siema";
    cout << std::string(50,'-') << std::endl;

    
}