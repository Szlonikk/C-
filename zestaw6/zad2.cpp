#include<iostream>
#include<functional>

using namespace std;

int main()

{


    //   function<int(int)> fib1 = [&fib1](int n) -> int
    //   {
    //         if(n <= 2)
    //               return 1;
    //         else
    //               return fib1(n-1) + fib1(n-2);
    //   };
    auto fib = [](int n, auto&& fib) {
    if (n <= 1) return n;
    return fib(n - 1, fib) + fib(n - 2, fib);
    };
    for(int i=0;i<=10;++i)
    cout<<fib(i,fib)<<" ";

}