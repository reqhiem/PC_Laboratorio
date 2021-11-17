#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

void bapc(string &p, int n, string &sarr){
    deque<int> arr;

    string aux = "";
    if(n != 0)
        for(int i=1; i<sarr.length(); i++){
            if(sarr[i] == ',' || sarr[i] == ']'){
                arr.push_back(stoi(aux));
                aux = "";
            }
            else aux += sarr[i];
        }

    int sent = 1;
    for(auto op : p){
        if(op == 'R'){
            sent = (sent == 1) ? -1 : 1;
        }else{
            if(arr.size() == 0){
                cout << "error" << endl;
                return;
            }else{
                if(sent == 1) arr.pop_front();
                else arr.pop_back();
            }
        }
    }

    if(sent == 1){
        cout << "[";
        for(auto it = arr.begin(); it != (arr.end()-1); it++){
            cout << *it << ",";
        }
        cout << *(arr.end()-1) << "]" << endl;
    }else{
        cout << "[";
        for(auto it = arr.rbegin(); it != (arr.rend()-1); it++){
            cout << *it << ",";
        }
        cout << *(arr.rend()-1) << "]" << endl;
    }

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int T;
    cin >> T;
    string p, sarr;
    int n;

    while(T--){
        cin >> p;
        cin >> n;
        cin >> sarr;
        bapc(p, n, sarr);
    }
    return 0;
}
