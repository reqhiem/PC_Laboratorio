//Islands problem from Open Kattis
#include <iostream>
#include <string>
using namespace std;

int R,C, j, tmpCurrent;
string rowstr;
int grid[55][55];
int tmp[3025][2];

void dfs(int x, int y){
    if(x < 0 || x >= R || y < 0 || y >= C) return;
    if(grid[x][y] == 4 || grid[x][y] == 2) return;

    grid[x][y] = 4;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main(int argc, char const *argv[])
{
    tmpCurrent = 0;
    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> rowstr;
        j = 0;
        for(auto car : rowstr){
            if(car == 'L'){
                tmp[tmpCurrent][0] = i;
                tmp[tmpCurrent][1] = j;
                grid[i][j++] = 1;
                tmpCurrent++;
            }
            else if(car == 'W') grid[i][j++] = 2;
            else grid[i][j++] = 3;
        }
    }

    //Relajacion no hay islas
    if(tmpCurrent == 0){
        cout << "0" << endl;
        return 0;
    }

    //Caso contrario
    int islas = 0;
    for(int i=0; i<tmpCurrent; i++){
        if(grid[tmp[i][0]][tmp[i][1]] == 1){
            dfs(tmp[i][0],tmp[i][1]);
            islas++;
        }
    }
    
    //print grid
    /* for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    } */

    cout << islas << endl;

    return 0;
}