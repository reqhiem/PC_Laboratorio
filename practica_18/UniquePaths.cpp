#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int uniquePaths(int m, int n) {
    vvi memo(m, vi(n, 0));

    for(int i=0; i<m; i++) memo[i][0] = 1;
    for(int j=0; j<n; j++) memo[0][j] = 1;

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            memo[i][j] = memo[i-1][j] + memo[i][j-1];
        }
    }

    return memo[m-1][n-1];      
}

int main(int argc, char const *argv[])
{
    cout << uniquePaths(3, 7) << endl;
    return 0;
}
