#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>

#define MAX_VER 3610
#define INF 9999999

using namespace std;

typedef pair<int,int> pp;

struct vertex
{
	vector<int> edges;
	int distance;
};

vertex graph[MAX_VER];

void dijkstra(int source){
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    graph[source].distance = 0;
    pq.push(make_pair(0, source));

    while(!pq.empty()){
        int u = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if(distance > graph[u].distance) continue;
        
        for(int i=0; i<graph[u].edges.size(); i++){
            int v = graph[u].edges[i];
            
            if(distance + 1 < graph[v].distance ){
                graph[v].distance = distance + 1;
                pq.push(make_pair(graph[v].distance, v));
            }
        }
    }
}

void solve(){
    //init graph
    for(int i=0; i<MAX_VER; i++){
        graph[i].edges.clear();
        graph[i].distance = INF;
    }


    int nb, tt;
    cin >> nb >> tt;
    for(int i = 0; i < nb; i++){
        int button;
        cin >> button;
        for(int aux = 0; aux <= 3600; ++aux ){
            int aux2 = aux + button;
            if(aux2 < 0) aux2 = 0;
            else if(aux2 > 3600) aux2 = 3600;
            graph[aux].edges.push_back(aux2);
        }
    }

    dijkstra(0);
    for(int i=0; i<MAX_VER - tt; ++i){
        int aux = i + tt;
        if(graph[aux].distance < INF){
            cout << graph[aux].distance << " " << i << endl;
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    while(N--){
        solve();
    }
    return 0;
}
