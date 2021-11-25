/**
 *  autor: Joel Perca
 *  problema: Rectangle Cutting de CSES https://cses.fi/problemset/task/1744
*/

#include <iostream>
#include <vector>
#define INF (int)1e9
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int a,b;

void RectangleCutting(){
    vvi memo(a+1, vi(b+1));
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            if(i==j){
                memo[i][j] = 0;
            }else{
                memo[i][j] = INF;
                for(int k=1; k<i; k++){
                    memo[i][j] = min(memo[i][j], memo[k][j] + memo[i-k][j] + 1);
                }
                for(int k=1; k<j; k++){
                    memo[i][j] = min(memo[i][j], memo[i][k] + memo[i][j-k] + 1);
                }
            }
        }
    }
    cout << memo[a][b] << endl;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    RectangleCutting();

    return 0;
}
