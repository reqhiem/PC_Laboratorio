#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


void dfs(vvi & rooms, vi &visited, int u){
    visited[u] = 1;
    for(int j = 0; j < (int) rooms[u].size(); j++){
        int vec = rooms[u][j];
        if(visited[vec] == 0){
            dfs(rooms, visited, vec);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vi visited(n, 0);
    dfs(rooms, visited, 0);
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vvi rooms = {{1}, {2}, {3}, {}};
    //vvi rooms = {{1,3}, {3,0,1}, {2}, {0}};
    (canVisitAllRooms(rooms)) ? cout << "Yes" : cout << "No";
    return 0;
}
