/**
 * @autor: Joel Perca
 * @problema: Dungeon Master de Open Kattis https://open.kattis.com/problems/dungeon
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int L, R, C;
vvi offsets = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

bool isValid(int a, int b, int c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> L >> R >> C) {
        tuple<int,int,int> start, end;

        if(L == 0 || R == 0 || C == 0) {
            break;
        }

        vector<vector<vector<int>>> v(L);
        for(auto& i : v) {
            i.resize(R, vector<int>(C, -2));
        }

        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                for(int k = 0; k < C; k++) {
                    char car;
                    cin >> car;
                    if(car == '#') {
                        v[i][j][k] = -1;
                    }
                    if(car == 'S') {
                        get<0>(start) = i;
                        get<1>(start) = j;
                        get<2>(start) = k;
                    }
                    if(car == 'E') {
                        get<0>(end) = i;
                        get<1>(end) = j;
                        get<2>(end) = k;
                    }
                }
            }
        }

        queue<tuple<int,int,int>> Q;
        Q.push(start);

        v[get<0>(start)][get<1>(start)][get<2>(start)] = 0;

        while(!Q.empty()) {
            auto curr = Q.front();
            Q.pop();
            
            for(auto &offset: offsets){
                int x = get<0>(curr) + offset[0];
                int y = get<1>(curr) + offset[1];
                int z = get<2>(curr) + offset[2];

                if(isValid(x, y, z) && v[x][y][z] == -2) {
                    v[x][y][z] = v[get<0>(curr)][get<1>(curr)][get<2>(curr)] + 1;
                    Q.push({x, y, z});
                }
            }
        }

        if(v[get<0>(end)][get<1>(end)][get<2>(end)] < 0) {
            cout << "Trapped!" << endl;
        }
        else {
            cout << "Escaped in " << v[get<0>(end)][get<1>(end)][get<2>(end)] << " minute(s)." << endl;
        }
    }
}


bool isValid(int a, int b, int c) {
    return (a >= 0 && b >= 0 && b >= 0 && a < L && b < R && c < C);
}