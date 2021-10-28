#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

vector<int> solve(vector<vector<int>> &mk){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;

    for(int i = 0; i < mk.size(); i++){
        for(int j = 0; j < mk[i].size(); j++){
            pq.push(mk[i][j]);
        }
    }

    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}


int main(int argc, char const *argv[]){
    vector<vector<int>> mk = {{1,4,5}, {1,3,4}, {2,6}};
    for(auto el :solve(mk)) cout << el << " ";
    cout << endl;
    return 0;
}
