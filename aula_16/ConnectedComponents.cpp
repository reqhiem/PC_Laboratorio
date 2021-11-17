#include <iostream>
#include <vector>
#include <string>
using namespace std;

int graph[30][30], N, V, E, a, b;

void init(){
    for(int i = 0; i < 30; i++)
        for(int j = 0; j < 30; j++)
            graph[i][j] = 0;
}
void clear(){
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            graph[i][j] = 0;
}

void solve(int testCase){
    vector<int> visited(30, 0);
    vector<vector<int>> components;
    
    
    cout << "Case #" << testCase << ":";

}


int main(int argc, char const *argv[])
{
    init();

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> V >> E;
        clear();
        for(int j=0; j<E; j++){
            cin >> a >> b;
            graph[a-97][b-97] = 1;
        }
        solve(i+1);
    }
    return 0;
}
