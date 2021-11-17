//Flood Fill problem
#include <iostream>
#include <vector>

using namespace std;


void _floodFill(vector<vector<int>> &grid, int i, int j, int color, int oldCol){
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != oldCol)
        return;
    grid[i][j] = color;

    if(i==0 && j==0){
        _floodFill(grid, i+1, j, color, oldCol);
        _floodFill(grid, i, j+1, color, oldCol);
    }
    else if(i==0 && j==grid[0].size()-1){
        _floodFill(grid, i+1, j, color, oldCol);
        _floodFill(grid, i, j-1, color, oldCol);
    }
    else if(i==grid.size()-1 && j==0){
        _floodFill(grid, i-1, j, color, oldCol);
        _floodFill(grid, i, j+1, color, oldCol);
    }
    else if(i==grid.size()-1 && j==grid[0].size()-1){
        _floodFill(grid, i-1, j, color, oldCol);
        _floodFill(grid, i, j-1, color, oldCol);
    }
    else if(i==0){
        _floodFill(grid, i+1, j, color, oldCol);
        _floodFill(grid, i, j+1, color, oldCol);
        _floodFill(grid, i, j-1, color, oldCol);
    }
    else if(i==grid.size()-1){
        _floodFill(grid, i-1, j, color, oldCol);
        _floodFill(grid, i, j+1, color, oldCol);
        _floodFill(grid, i, j-1, color, oldCol);
    }
    else if(j==0){
        _floodFill(grid, i+1, j, color, oldCol);
        _floodFill(grid, i-1, j, color, oldCol);
        _floodFill(grid, i, j+1, color, oldCol);
    }
    else if(i==0 && j==grid[0].size()-1){
        _floodFill(grid, i+1, j, color, oldCol);
        _floodFill(grid, i-1, j, color, oldCol);
        _floodFill(grid, i, j-1, color, oldCol);
    }
    else{
        _floodFill(grid, i+1, j, color, oldCol);
        _floodFill(grid, i-1, j, color, oldCol);
        _floodFill(grid, i, j+1, color, oldCol);
        _floodFill(grid, i, j-1, color, oldCol);
    }

    /* floodFill(grid, i+1, j, color, oldCol);
    floodFill(grid, i-1, j, color, oldCol);
    floodFill(grid, i, j+1, color, oldCol);
    floodFill(grid, i, j-1, color, oldCol); */
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1,1,1},
                                {1,1,0},
                                {1,0,1}};
    _floodFill(grid, 1, 1, 2, 1);

    for(auto i : grid){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
