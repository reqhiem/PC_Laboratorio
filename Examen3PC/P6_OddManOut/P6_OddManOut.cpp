/**
 * @autor: Joel Perca
 * @problema: Odd Man Out from https://open.kattis.com/problems/oddmanout
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, n = 0, G, tmp, res;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(n++ < N){
        unordered_map<int, int> odds;
        cin >> G;
        for(int i = 0; i < G; i++){
            cin >> tmp;
            odds[tmp]++;
        }

        for(auto it = odds.begin(); it != odds.end(); it++){
            if(it->second == 1){
                res = it->first;
            }
        }
        cout << "Case #" << n << ": " << res << endl;
    }
    return 0;
}
