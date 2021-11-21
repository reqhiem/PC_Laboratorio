#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const int MS = 1e4 + 10;

int N, M, j, curr;
int grid[110][110];
bool vis[110][110];
int offsets[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int tree[MS][2];
string linestr;

bool isValid(int row, int col)
{
    if (row < 0 || col < 0
        || row >= N || col >= M)
        return false;
 
    if (vis[row][col])
        return false;

    return true;
}

void bfs(int row, int col){
    queue<pair<int,int>> q;
    
    q.push({ row, col });
    vis[row][col] = true;
    int color = 3;
    grid[row][col] = color;
    while(!q.empty()){
        pair<int,int> cell  = q.front();
        q.pop();
        int x = cell.first;
        int y = cell.second;

        for(int i = 0; i < 4; i++){
            int nx = x + offsets[i][0];
            int ny = y + offsets[i][1];

            if(isValid(nx, ny) && grid[nx][ny] == 1){
                vis[nx][ny] = true;
                q.push({ nx, ny });
                grid[nx][ny] = color;
            }
        }
        color++;
    }
}

void solve(){
    memset(vis, false, sizeof(vis));

    //print tree
    /* for(int i = 0; i < curr; i++){
        cout << tree[i][0] << " " << tree[i][1] << endl;
    } */

    bfs(0,1);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    curr = 0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> linestr;
        j = 0;
        for(auto &car : linestr){
            if(car == 'T'){
                grid[i][j++] = 1;
                tree[curr][0] = i;
                tree[curr++][1] = j-1;
            }else grid[i][j++] = 0;
        }
    }

    //print grid
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    //apply rules
    solve();

    //print grid
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
