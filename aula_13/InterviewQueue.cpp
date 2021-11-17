#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;

const int MS = 10e5+10;
int n, x, arr[MS];

void solve(int *arr, int &N){
    int time = 0;
    vector<vector<int>> ans;
    queue<int> q;

    while(true){
        int ops = 0;
        vector<int> aux;

        if(time != 0){
            N = q.size();
            for(int i=0; i<N; i++){
                arr[i] = q.front();
                q.pop();
            }
        }

        for(int i=0; i<N; i++){
            bool isdel = false;
            if(i==0 && N > 1 && arr[i] < arr[i+1]){
                ops++;
                isdel = true;
                aux.push_back(arr[i]);
            }else if(i==N-1 && N > 1 && arr[i] < arr[i-1]){
                ops++;
                isdel = true;
                aux.push_back(arr[i]);
            }else if(N > 2 && (arr[i] < arr[i-1] || arr[i] < arr[i+1])){
                ops++;
                isdel = true;
                aux.push_back(arr[i]);
            }
            if(!isdel) q.push(arr[i]);
        }



        if(ops == 0) break;
        else{
            time++;
            ans.push_back(aux);
        }
    }

    cout << time << endl;

}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    solve(arr, n);

    return 0;
}
