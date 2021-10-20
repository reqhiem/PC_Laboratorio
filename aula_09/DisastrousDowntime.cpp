/*
EJERCICIO ACEPTADO POR OPEN KATTIS COMO SOLUCIÓN
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

const int ms = 1e05 + 5;

int N, K, k=0, x;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    map<int, int> mp;

    while (k++ < N){
        cin >> x;
        mp[x] = (mp[x] != 0) ? mp[x] + 1 : 1;
        mp[x+1000] = (mp[x+1000] != 0) ? mp[x+1000] -1 : -1;
    }

    vector<int> diff(mp.size(), 0);
    int cont = 0;

    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it == mp.begin()) diff[cont] = it->second;
        else diff[cont] = diff[cont-1] + it->second;
        
        cont++;
    }

    cout << ceil(*max_element(diff.begin(), diff.end())/(float)K) << endl;
    
    return 0;
}