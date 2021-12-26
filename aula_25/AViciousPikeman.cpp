/**
 * @autor: Joel Perca
 * @problema: A vicious pikeman https://open.kattis.com/problems/pikemaneasy
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define MOD 1000000007

typedef unsigned long long int ll;
typedef vector<ll> vll;

ll N, T, A, B, C, t0;

void optimal(ll N, ll T, vll& lis){
    ll total_time = 0, penalty = 0;
    for(int i = 0; i < N; i++){
        ll t = lis[i];
        if(total_time + t > T){
            cout << i << " " << penalty << endl;
            return;
        }
        total_time += t;
        penalty  = (penalty + total_time) % MOD;
    }
    cout << N << " " << penalty << endl;
}

int main(int argc, char const *argv[])
{
    cin >> N >> T;
    cin >> A >> B >> C >> t0;

    vll v(N);
    v[0] = t0;

    for (int i = 1; i < N; ++i) {
        v[i] = ((A * v[i-1] + B) % C) + 1;
    }
    sort(v.begin(), v.end());
    optimal(N, T, v);

    return 0;
}
