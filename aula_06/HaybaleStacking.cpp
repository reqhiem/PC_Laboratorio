#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ms = 1e06 + 5;

int N, K, a, b;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    vector<int> diff(N, 0);
    vector<int> arr(N, 0);

    while(K--){
        cin >> a >> b;
        diff[a-1]++; diff[b]--;
    }
    
    arr[0] = diff[0];
    for(int i=1; i<N; i++){
        arr[i] = arr[i-1] + diff[i];
    }

    sort(arr.begin(), arr.end());

    if(N%2==0) cout << (arr[(N/2) - 1] + arr[N/2])/2.0 << endl;
    else cout << arr[(N+1)/2 -1] << endl;

    return 0;
}
