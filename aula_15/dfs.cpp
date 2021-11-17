#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs_recursive(vector<vector<int>> &G, vector<int> &visited, int node){
    cout << node << " ";
    visited[node] = 1;
    for(int v = 0; v < G[node].size(); v++){
        if(!visited[v] && G[node][v] == 1){
            visited[G[node][v]] = 1;
            dfs_recursive(G, visited, v);
        }
    }
}

void dfs_iterative(vector<vector<int>> &G, int node){
    
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    vector<int> visited(graph.size(), 0);

    dfs_recursive(graph, visited, 0);

    return 0;
}
