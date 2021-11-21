#include <iostream>
#include <queue>
#define ROW 5
#define COL 5

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<bool>> vvb;

vvi offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(vvb &vis, int row, int col)
{
    if (row < 0 || col < 0
        || row >= ROW || col >= COL)
        return false;
 
    if (vis[row][col])
        return false;

    return true;
}

void bfs(vvi &grid, int row, int col, vvb &vis) {
    queue<pair<int, int> > q;

    q.push({ row, col });
    vis[row][col] = true;
 
    while (!q.empty()) {
 
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
 
        q.pop();

        for (int i = 0; i < 4; i++) {
 
            int adjx = x + offsets[i][0];
            int adjy = y + offsets[i][1];
 
            if (isValid(vis, adjx, adjy)) {
                q.push({ adjx, adjy });
                vis[adjx][adjy] = true;
                grid[adjx][adjy] = grid[x][y] + 1;
            }
        }
    }
}


int main(int argc, char const *argv[])
{   
    int position = 0;
    vvi offsets = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    vector<vector<bool>> visited(5, vector<bool>(5, false));
    vvi graph(5, vector<int>(5, -1));
    graph[1][2] = 0;

    //print the Grid
    cout << "Initial grid: " << endl;
    for(auto vec : graph){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }

    bfs(graph, 1, 2, visited);

    //print the Grid after BFS
    cout << "Final grid: " << endl;
    for(auto vec : graph){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
