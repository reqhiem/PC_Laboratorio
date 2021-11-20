#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

void dfs(vii &grid, int i, int j, int n, int m){
    if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return;
    grid[i][j] = 0;
    dfs(grid, i+1, j, n, m);
    dfs(grid, i-1, j, n, m);
    dfs(grid, i, j+1, n, m);
    dfs(grid, i, j-1, n, m);
}

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1 && grid[i][j] == 1){
                dfs(grid, i, j, n, m);
            }
        }
    }
    int res = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j] == 1) res++;
        
    return res;
}

int main(int argc, char const *argv[]){
    vii grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << numEnclaves(grid) << endl;
    return 0;
}
