#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

typedef vector<int> vi;

void threePointers(vi &arr, int target){

    int p=0, q=arr.size()-1, m = floor((0 + arr.size()-1)/2);
    int res[3] = {p, m, q};

    while(res[0] != res[1] || res[1] != res[2]){
        if((arr[res[0]] + arr[res[1]] + arr[res[2]]) < target && (target - (arr[res[0]] + arr[res[1]] + arr[res[2]]) < arr[res[1]])) res[0]++;
        else if((arr[res[0]] + arr[res[1]] + arr[res[2]]) < target && (target - (arr[res[0]] + arr[res[1]] + arr[res[2]]) > arr[res[1]])) res[1]++;
        else if((arr[res[0]] + arr[res[1]] + arr[res[2]]) > target && ((arr[res[0]] + arr[res[1]] + arr[res[2]]) - target < arr[res[1]])) res[1]--;
        else if((arr[res[0]] + arr[res[1]] + arr[res[2]]) > target && ((arr[res[0]] + arr[res[1]] + arr[res[2]]) - target > arr[res[1]])) res[2]--;
        else if((arr[res[0]] + arr[res[2]] + arr[res[1]]) == target) break;
    }


    if(res[0] != res[1] && res[1] != res[2]){
        sort(res, res + 3);
        cout << "[" << res[0] << "," << res[1] << "," << res[2] << "] positions" << endl; 
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //vi a = {2,5,7,9,21};
    //int target =21;

    vi a = {1,2,4,5,12};
    int target=19;

    threePointers(a, target);

    return 0;
}
