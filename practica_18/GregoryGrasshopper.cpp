#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <cstring>
using namespace std;

#define LV 8

typedef vector<int> vi;
typedef vector<vi> vvi;

int R,C,Gr,Gc,Lr,Lc, currX, currY;
static int steps[][2] = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};

bool visited[110][110];
int grid[110][110];

void Gregory(){
    Gr--; Gc--; Lr--; Lc--;
    //Ya se encuentra en la hoja
    if(Lr == Gr && Lc == Gc) {
        cout << "0\n";
        return;
    }

    //caso contrario
    memset(visited, false, sizeof(visited));
    for (int i=0; i<R; i++) for (int j=0; j<C; j++) grid[i][j] = INT_MAX;


    stack<pair<int,int>> unvisited;
    unvisited.push(make_pair(Gr, Gc));
    grid[Gr][Gc] = 0;
    
    while (!unvisited.empty()){
        currX = unvisited.top().first;
        currY = unvisited.top().second;
        unvisited.pop();

        visited[currX][currY] = true;

        for (int i = 0; i < LV; i++){
            int nr = currX + steps[i][0];
            int nc = currY + steps[i][1];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C ){
                if(grid[nr][nc] > (grid[currX][currY] + 1)){
                    grid[nr][nc] = grid[currX][currY] + 1;
                    unvisited.push({nr, nc});
                }
            }
        }
    }

    //print the grid
    /* for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    } */

    (grid[Lr][Lc] == INT_MAX) ? cout << "impossible\n" : cout << grid[Lr][Lc] << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    while(cin >> R >> C >> Gr >> Gc >> Lr >> Lc){
        Gregory();
    }
    return 0;
}
