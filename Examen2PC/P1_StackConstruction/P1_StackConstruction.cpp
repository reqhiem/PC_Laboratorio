/**
 *  autor: Joel Perca
 *  problema: Stack Construction de Open Kattis https://open.kattis.com/problems/stack
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 200;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi tmp;
string str;

int min_oper(int i, int j) {
    if (i > j) return 0;
    if (tmp[i][j] == -1) {
        tmp[i][j] = 1+min_oper(i, j-1);

        for (int k = i; k < j; ++k)
            if (str[k] == str[j])
                tmp[i][j] = min(tmp[i][j], min_oper(i,k) + min_oper(k+1,j-1));
    }
    return tmp[i][j];
}

int main() {
    int T;
    cin >> T >> ws;
    while (T--) {
        tmp.assign(MAXN, vi(MAXN+1, -1));
        getline(cin, str);
        int n = str.length();
        cout << min_oper(0, n-1)*2 + n << endl;
    }
    return 0;
}
