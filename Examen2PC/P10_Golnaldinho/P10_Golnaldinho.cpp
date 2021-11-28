/**
 * problema: Golnáldinho de Beecrowd // https://www.beecrowd.com.br/judge/es/problems/view/2792
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


typedef vector<int> vi;
const int MAXN = 500005;

int golnaldinho(vi &arr, int x){
    int res = 0;
    while(x > 0){
        res += arr[x];
        x -= x & (-x);
    }
    return res;
}

int  main(int argc, char const *argv[]){
    int N, xx, i;
    cin >> N;
    vi arr(MAXN, 0);
    for(i = 1; i <= N; i++){
        cin >> xx;
        cout << (xx - golnaldinho(arr, xx));
        if(i == N) 
            cout << endl;
        else 
            cout << " ";
        while (xx < MAXN){
            arr[xx] += 1;
            xx += xx & (-xx);
        } 
    }

    return 0;
}
