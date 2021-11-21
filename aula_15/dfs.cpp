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
    vector<int> S;
    vector<bool> visited(G.size(), false);
    S.push_back(node);
    visited[node] = true;
    cout << node << " ";

    while(!S.empty()){
        int v = S.back();
        S.pop_back();
        for(int i=0; i<G.size(); i++){
            if(G[v][i] == 1 && !visited[i]){
                S.push_back(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
    cout << endl;

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
    cout << "DFS Recursive: ";
    dfs_recursive(graph, visited, 0); cout << endl;

    cout << "DFS Iterative: ";
    dfs_iterative(graph, 0);
    return 0;
}
