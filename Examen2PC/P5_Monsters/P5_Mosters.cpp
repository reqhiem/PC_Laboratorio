/**
 *  autor: Joel Perca
 *  problema: String de CSES de https://cses.fi/problemset/result/3172023/
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

vvi offset = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

char directions[] = {'U', 'D', 'R', 'L'};
int path[1010][1010];
int n,m;
vs grid;

void monsters(){
    
    queue<pair<int,int>> q;
    int x,y;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'M')
                q.push({i,j});
            else if (grid[i][j] == 'A')
                x = i, y = j;
        }
    }
        
    q.push({x,y});
    path[x][y] = -1;
    while(!q.empty()) {
        auto curr = q.front();
        x = curr.first, y = curr.second;
        q.pop();
        if ((x == 0 || x == n-1 || y == 0 || y == m-1) && grid[x][y] == 'A') {
            cout << "YES" << endl;
            string res;
            int d = path[x][y];
            while(d != -1) {
                res += directions[d];
                x = x - offset[d][0];
                y = y - offset[d][1];
                d = path[x][y];
            }
            reverse(res.begin(), res.end());
            cout << res.size() << endl;
            cout << res;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + offset[i][0];
            int yy = y + offset[i][1];
            if (xx<0 || xx>=n || yy<0 || yy>=m || grid[xx][yy] != '.' ) 
                continue;
            else {
                grid[xx][yy] = grid[x][y];
                if (grid[xx][yy] == 'A') 
                    path[xx][yy] = i;
                q.push({xx,yy});
            }
        }
    }
    cout << "NO";
}    
int main(int argc, char **argv){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >>n >> m;
    grid.resize(n);
    for (int i=0; i<n; i++)
        cin >> grid[i];

    monsters();
    cout << endl;
}