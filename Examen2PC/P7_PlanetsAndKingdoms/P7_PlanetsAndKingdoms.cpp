/**
 *  autor: Joel Perca
 *  problema: Planets and Kingdoms de https://cses.fi/problemset/task/1683/
*/
#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

vector<int> eachPlanet;
int kingdom = 1;

class Graph
{
	int V;
	list<int> *adj;
	void fillOrder(int v, bool visited[], stack<int> &Stack){
        visited[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
            if(!visited[*i])
                fillOrder(*i, visited, Stack);

        Stack.push(v);
    }

	void DFSUtil(int v, bool visited[]){
        visited[v] = true;
        eachPlanet[v] = kingdom;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited);
    }
public:
	Graph(int V){
        this->V = V;
	    adj = new list<int>[V];
    }
	void addEdge(int v, int w){
        adj[v].push_back(w); 
    }
	void printSCCs(){
        stack<int> Stack;
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;

        for(int i = 0; i < V; i++)
            if(visited[i] == false)
                fillOrder(i, visited, Stack);

        Graph gr = getTranspose();

        for(int i = 0; i < V; i++)
            visited[i] = false;

        while (Stack.empty() == false){

            int v = Stack.top();
            Stack.pop();

            if (visited[v] == false)
            {
                gr.DFSUtil(v, visited);
                kingdom++;
            }
        }
    }
	Graph getTranspose(){
        Graph g(V);
        for (int v = 0; v < V; v++){
            list<int>::iterator i;
            for(i = adj[v].begin(); i != adj[v].end(); ++i){
                g.adj[*i].push_back(v);
            }
        }
        return g;
    }
};

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b;
    cin >> n >> m;

    eachPlanet.resize(n);
    Graph g1(n);
    
    for(int i=0; i<m; i++){
        cin >> a >> b;
        g1.addEdge(a-1,b-1);
    }
    g1.printSCCs();

    cout << --kingdom << endl;
    for(int i=0; i<eachPlanet.size(); i++){
        cout << eachPlanet[i] << " ";
    }
    cout << endl;

	return 0;
}
