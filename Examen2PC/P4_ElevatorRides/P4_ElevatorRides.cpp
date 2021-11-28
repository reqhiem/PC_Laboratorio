/**
 *  autor: Joel Perca
 *  problema: Elevator Rides de https://cses.fi/problemset/result/3172793/
*/
#include <iostream>
#include <vector>

using namespace std;

#define INF INT_MAX 

typedef long long ll;
typedef vector<ll> vll;

int n;
ll mw;

int main() {
    
    cin >> n >> mw;
    vll arr(n);

    for (int i = 0; i < n; i++) 
        cin >> arr[i];
 
    vector<pair<ll, ll>> memo(1 << n); 
    memo[0] = {1, 0};
 
    for (int k = 1; k < (1 << n); k++) {
        pair<ll, ll> aux = {INF, INF};
        for (int i = 0; i < n; i++) {
            if (((1 << i) & k) == 0) continue;
            auto res = memo[(1 << i) ^ k];
            if (res.second + arr[i] <= mw) {
                res.second += arr[i];
            } else {
                res.first += 1;
                res.second = arr[i];
            }
            aux = min(aux, res);
        }
        memo[k] = aux;
    }
    cout << memo[(1 << n) - 1].first;
 
    return 0;
}