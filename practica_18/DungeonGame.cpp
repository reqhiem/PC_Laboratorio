#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    vvi memo(m, vi(n, 0));
    memo[m-1][n-1] = (dungeon[m-1][n-1] > 0) ? 0 : dungeon[m-1][n-1];

    //Ultima columna
    for(int i=m-2; i>=0; i--)
        memo[i][n-1] = (memo[i+1][n-1] + dungeon[i][n-1] > 0) ? 0 : memo[i+1][n-1] + dungeon[i][n-1];

    //Ultima fila
    for(int i=n-2; i>=0; i--)
        memo[m-1][i] = (memo[m-1][i+1] + dungeon[m-1][i] > 0) ? 0 : memo[m-1][i+1] + dungeon[m-1][i];
    
    //Resto de casos
    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            memo[i][j] = (max(memo[i+1][j], memo[i][j+1]) + dungeon[i][j] >= 0) ? 0 : max(memo[i+1][j], memo[i][j+1]) + dungeon[i][j];
        }
    }
    

    //Imprimir memo
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    return (memo[0][0] > 0) ? 1 : abs(memo[0][0]) + 1;

}
int main(int argc, char const *argv[])
{
    //vvi dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    vvi dungeon = {{-3,5}};
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}
