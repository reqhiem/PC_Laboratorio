#include <iostream>
typedef unsigned long long ull;

using namespace std;

//recursiva
ull fib(ull n){
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

int main(int argc, char const *argv[])
{
    cout << fib(10) << endl;
    return 0;
}
