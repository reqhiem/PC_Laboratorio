//https://cses.fi/problemset/task/1643/

#include <iostream>
#include <climits>
using namespace std;
typedef long long ull;



ull n, i=0, arr[200002];

void maxSumSubarray(ull *arr, ull n){
    ull bs = LLONG_MIN, cs = 0;
 
    for (ull i = 0; i < n; i++)
    {
        cs = cs + arr[i];
        bs = max(bs, cs);
        cs = (cs < 0) ? 0 : cs;
    }
    cout << bs << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    while (i < n){
        cin >> arr[i++];
    }

    maxSumSubarray(arr, n);
    
    return 0;
}
