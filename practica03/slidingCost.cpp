//https://cses.fi/problemset/stats/1077/
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;

ll n,k, arr[200005], i=0;

void slidingCost(ll *arr, ll n){

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    while (i < n){
        cin >> arr[i++];
    }

    slidingCost(arr, n);
    
    return 0;
}
