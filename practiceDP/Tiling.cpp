#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

//Tiling problem
int tiling(int n){
    if (n <= 1) return n;
    vi dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    cout << tiling(4) << endl;
    return 0;
}
