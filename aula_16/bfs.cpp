#include <iostream>
#include <queue>
using namespace std;


int main(int argc, char const *argv[])
{
    vector<vector<int>> visited(5, vector<int>(5, 0));
    vector<vector<int>> graph(5, vector<int>(5, -1));
    graph[1][2] = 0;

    int i=1, j=2;
    queue<pair<int,int>> Q;
    int cont = 0;

    Q.push({i,j});
    visited[i][j] = 1;

    while (!Q.empty()){
        auto n = Q.front();
        Q.pop();
        vector<pair<int,int>> neighbors = {{n.first+1, n.second}, {n.first-1, n.second}, {n.first, n.second+1}, {n.first, n.second-1}};
        for(auto vec : neighbors){
            if(visited[vec.first][vec.second] == 0 && (vec.first >= 0 && vec.first < 5) && (vec.second >= 0 && vec.second < 5)){
                Q.push(vec);
                visited[vec.first][vec.second] = 1;
                graph[vec.first][vec.second] = graph[n.first][n.second] + 1;
            }
        }
    }

    //print the matrix
    for(auto vec : graph){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
