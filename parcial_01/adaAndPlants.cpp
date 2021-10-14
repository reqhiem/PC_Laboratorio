/**
 *  @descripcion: Solución y aceptada
*/

#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

const int ms = 2e05 + 10;

int c = 0,p,T,N,K, arr[ms];

void solve(){
    int mf = 0, d;
    set<pair<int,int>> aux;
    for(int i = 0; i < N; i++){
        aux.insert({arr[i],i});

        d = aux.rbegin()->first - aux.begin()->first;
        if(d > mf) mf = d;
        if(i-K-1 >= 0) aux.erase({arr[i-K-1],i-K-1});
    }
    cout << mf << endl;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    while(c++ < T){
        p = 0;
        cin >> N >> K;
        while(p < N) cin >> arr[p++];
        solve();
    }
    return 0;
}
