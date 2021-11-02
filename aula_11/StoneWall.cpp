#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> &H){
    stack<int> s;
    int aux = 0;

    for(int i = 0; i < H.size(); i++){
        while(!s.empty() && s.top() > H[i]) s.pop();
        if(s.empty()){
            s.push(H[i]);
            aux++;
        }else if(s.top() == H[i]){
            ;
        }
        else if(s.top() < H[i]){
            aux++;
            s.push(H[i]);
        }
    }
    return aux;
}

int main(int argc, char const *argv[]){
    vector<int> H = {8,8,5,7,9,8,7,4,8};

    cout << solution(H) << "\n";
    return 0;
}
