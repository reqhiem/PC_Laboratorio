/**
 *  @descripcion: Este programa fue admitido por el jurado como una solución
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <climits>

using namespace std;
typedef long long ll;

const int ms = 2e05 + 10;

ll arr[ms], pre[ms], N, a, b, k=0;

void solve(){
    multiset<ll> s;
    pre[0] = arr[0];
    for(ll i=1; i<N; i++)  pre[i] = pre[i-1] + arr[i];
    

    s.insert(0);
    ll res = LONG_MIN;
    bool flag = false;

    res = max(res, pre[a-1]);

    for(ll i=a; i<N; i++){
        if(i-b>= 0){
            if(!flag){
                auto it = s.find(0);
                s.erase(it);
                flag = true;
            }
        }
        if(i-a >= 0) s.insert(pre[i-a]);
        res = max(res, pre[i] - *s.begin());

        if(i-b >= 0){
            auto it = s.find(pre[i-b]);
            s.erase(it);
        }
    }
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    cin >> N >> a >> b;
    while(k < N) cin >> arr[k++];
    solve();
    return 0;
}
