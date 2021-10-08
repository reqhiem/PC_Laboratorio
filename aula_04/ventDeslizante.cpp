#include <iostream>
#include <vector>
using namespace std;

int k, n, res = -99999;

void ventDeslizante(vector<int>& arr, int k, int n){

    for(int i=0; i<=(n - k); i++){
        int sum = arr[i];
        for(int j=i+1; j<(i+k); j++) sum += arr[j];
        if(sum > res) res = sum;
    }

    cout << res << endl;
}

void ventanaDeslizante(vector<int>& arr, int k, int n){
    int _res = 0;
    for(int i=0; i < k; i++) _res += arr[i];

    for(int i=k; i<n; i++){
        _res = ((_res + arr[i] - arr[i-k]) > res) ? (_res + arr[i] - arr[i-k]) : res;
    }
    cout << _res << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2,3,4,1,5};
    k = 3; n = arr.size();
    ventanaDeslizante(arr, k, n);
    return 0;
}
