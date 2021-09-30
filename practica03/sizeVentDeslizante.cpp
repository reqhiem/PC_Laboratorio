#include <iostream>
#include <vector>
using namespace std;

int k, n, res = -99999;

void sizeVentDeslizante(vector<int>& arr, int s, int n){
    int _res = 1, sum = 0;
    vector<int> mem = {0};

    for(int i = 0; i < n; i++){
        mem.push_back(mem.back() + arr[i]);
        if (arr[i] == s){            
            cout << _res << endl;
            return;
        }
    }

    for(int k=2; k <= n; k++){
        for(int r=2; r < mem.size(); r++){
            if((mem[r] - mem[r-k]) == s){
                cout << k << endl;
                return;
            }
        }
    }
    cout << "NO HAY SUBARREGLO CON ESA SUMA" << endl;

}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {2,4,2,5,1};
    k = 7; n = arr.size();
    sizeVentDeslizante(arr, k, n);
    return 0;
}
