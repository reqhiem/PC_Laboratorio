//LCS implementation in 3 diferentes way

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int lcs(string P0,  string Q0, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (P0[m-1] == Q0[n-1])
        return 1 + lcs(P0, Q0, m-1, n-1);
    else
        return max(lcs(P0, Q0, m, n-1), lcs(P0, Q0, m-1, n));
}

int lcs_aux(string P0,  string Q0, int m, int n, vector<vector<int>> &memo){
    if (m == 0 || n == 0)
        return 0;
    if (memo[m][n])
        return memo[m][n];
    if (P0[m-1] == Q0[n-1])
        return 1 + lcs_aux(P0, Q0, m-1, n-1, memo);
    else
        return max(lcs_aux(P0, Q0, m, n-1, memo), lcs_aux(P0, Q0, m-1, n, memo));
}

int lcs_mem(string P0,  string Q0){
    int m = P0.size();
    int n = Q0.size();
    vector<vector<int>> lcs_mem(m+1, vector<int>(n+1, 0));
    return lcs_aux(P0, Q0, m, n, lcs_mem);
}

int lcs_bu(string P0,  string Q0, int m, int n ){
    vector<vector<int>> lcs_mem(m+1, vector<int>(n+1, 0));
    int i,j;
    for(i=0; i<=m; ++i)
        for(j=0; j<=n; ++j)
            if(i==0 || j==0)
                lcs_mem[i][j] = 0;
            else if(P0[i-1] == Q0[j-1])
                lcs_mem[i][j] = 1 + lcs_mem[i-1][j-1];
            else
                lcs_mem[i][j] = max(lcs_mem[i][j-1], lcs_mem[i-1][j]);
    return lcs_mem[m][n];
}

int main(int argc, char const *argv[])
{
    string s1 = "abcdefghij";
    string s2 = "ecdgi";

    cout << lcs(s1, s2, s1.size(), s2.size()) << endl;
    cout << lcs_mem(s1, s2) << endl;      
    cout << lcs_bu(s1, s2, s1.size(), s2.size()) << endl;  
    return 0;
}
