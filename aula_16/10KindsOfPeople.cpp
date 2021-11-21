#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string line;
int mat[1005][1005], matTmp[1005][1005];
int R, C, N, r1, r2, c1, c2;
bool visited[1005][1005];
int offsets[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int i, int j, int fc, int fn){
    visited[i][j] = true;
    matTmp[i][j] = fn;
    for(int k = 0; k < 4; k++){
        int ni = i + offsets[k][0];
        int nj = j + offsets[k][1];
        if(ni >= 0 && ni < R && nj >= 0 && nj < C && !visited[ni][nj] && mat[ni][nj] == fc){
            dfs(ni, nj, fc, fn);
        }
    }

}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(visited, false, sizeof visited);

    cin >> R >> C;

    for(int i=0; i<R; i++){
        cin >> line;
        int j = 0;
        for(auto car : line) mat[i][j++] = (car == '0') ? 0 : 1;
    }

    int cont = 0;
    //Process
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(!visited[i][j]){
                dfs(i,j,mat[i][j],cont);
                cont++;
            }
        }
    }


    //Queries
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        if(matTmp[r1][c1] == matTmp[r2][c2]){
            if(mat[r1][c1] == 0) cout << "binary\n";
            else cout << "decimal\n";
        }else cout << "neither\n";
    }

    return 0;
}
