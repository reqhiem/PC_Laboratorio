#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef unsigned long long int ll;
typedef unordered_map<ll,ll> um;


ll A,B, sa, sb, C;

void solve(){
    um collatz;

    ll cont = 0, aa = A, bb = B, bres = 0, ares;
    collatz[A] = 0;
    cont++;

    while(A > 1){
        A = (A&1) ? 3*A + 1 : A >> 1;
        collatz[A] = cont++;
    }

    while(!collatz.count(B)){
        B = (B&1) ? 3*B + 1 : B >> 1;
        bres++;
    }

    ares = collatz[B];


    cout << aa << " needs " << ares << " steps, " << bb << " needs " << bres << " steps, they meet at " << B << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> A >> B){
        if (A == 0 && B == 0) break;
        solve();
    }
    
    return 0;
}
