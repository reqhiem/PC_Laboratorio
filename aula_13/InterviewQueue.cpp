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
    vector<int> tmp;

    queue<int> q;

    while(true){
        int ops = 0;
        vector<int> aux;

        if(time != 0){
            N = q.size();
            for(int i=0; i<N; i++){
                arr[i] = q.front();
                q.pop();
                tmp.pop_back();
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
            if(!isdel){
                q.push(arr[i]);
                tmp.push_back(arr[i]);
            }
        }



        if(ops == 0) break;
        else{
            time++;
            cout << endl;
            ans.push_back(aux);
        }
    }

    cout << time << endl;
    //print ans
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    //print tmp
    for(int i=0; i<tmp.size(); i++){
        cout << tmp[i] << " ";
    }
    cout << endl;

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
