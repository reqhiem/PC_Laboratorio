#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

static vvi offsets = {{-1,0},{0,-1},{1,0},{0,1}};

void dfs(vvi &heights, int i, int j, int par, vvi &visited){
    if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) return;

    if( heights[i][j] < par || visited[i][j] == 1) return;
    visited[i][j] = 1;
    for(int k = 0; k < offsets.size(); k++){
        int nr = i + offsets[k][0];
        int nc = j + offsets[k][1];
        dfs(heights, nr, nc, heights[i][j], visited);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    
    vvi res;
    int m = heights.size();
    int n = heights[0].size();

    if (m == 0 || n == 0) return res;

    vvi pacific(m, vi(n, 0));
    vvi atlantic(m, vi(n, 0));

    
    for(int i = 0; i < n; i++){
        dfs(heights, 0, i, INT_MIN, pacific);
        dfs(heights, m-1, i, INT_MIN, atlantic);
    }
    for(int i = 0; i < m; i++){
        dfs(heights, i, 0, INT_MIN, pacific);
        dfs(heights, i, n-1, INT_MIN, atlantic);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacific[i][j] == 1 && atlantic[i][j] == 1){
                vi aux;
                aux.push_back(i);
                aux.push_back(j);
                res.push_back(aux);
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vvi heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> res = pacificAtlantic(heights);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
