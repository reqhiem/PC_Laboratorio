#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<int,int> umii;

vvi offsets = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vvi &grid, int i, int j, int& col, umii &areas){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
    if(grid[i][j] == 0 || (grid[i][j] > 1 && grid[i][j] < col)) return;
    
    if(grid[i][j] == 1){
        grid[i][j] = col;
        areas[col]++;

        for(auto &offset : offsets){
            dfs(grid, i+offset[0], j+offset[1], col, areas);
        }
    }
}


int largestIsland(vector<vector<int>>& grid) {
    //volver a pintar el grid
    
    umii areas; //guardar las areas
    int col = 2; //empezar a colorear en 2

    vvi ceros; //para computar los ceros

    int n = grid.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                dfs(grid, i, j, col, areas);
                col++;
            }else if(grid[i][j] == 0){
                ceros.push_back({i,j});
            }
        }
    }

    int _max = -999;
    //relajacion no hay ceros para analizar, máxima de las areas
    if(ceros.size() == 0){
        for(int i=2; i<col; i++){
            _max = max(_max, areas[i]);
        }
        return _max;
    }

    //Para todos los ceros captados
    for(auto &cero : ceros){
        int i = cero[0]; int j = cero[1];
        int sum = 0;
        umii sumed;
        for(auto &offset: offsets){
            int ii = i+offset[0]; int jj = j+offset[1];
            if(ii>=0 && ii<n && jj>=0 && jj<n){
                if(grid[ii][jj] > 1 && sumed[grid[ii][jj]] != 1){
                    sumed[grid[ii][jj]] = 1;
                    sum += areas[grid[ii][jj]];
                }
            }
        }
        _max = max(_max, sum + 1);
    }

    return _max;
}

int main(int argc, char const *argv[])
{
    //vvi grid = {{1,0},{0,1}};
    //vvi grid = {{1,1},{1,0}};
    //vvi grid = {{1,1,0,0},{0,1,1,0},{0,0,0,1},{1,0,1,0}};
    vvi grid = {{1,1},{1,1}};
    /* vvi grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                {0,0,0,0,0,0,0,1,1,0,0,0,0}}; */

    //print grid
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << "After coloring:\n";
    cout << largestIsland(grid) << endl;
    return 0;
}
