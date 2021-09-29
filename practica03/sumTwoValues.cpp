#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

int n,x, i,j;

bool compare(pair<int,int> &a, pair<int,int> &b){
    return (a.second > b.second);
}

void sumTwoValues(vector<pair<int,int>> &arr, int n, int x){

    sort(arr.begin(), arr.end(), compare);

    auto it1 = arr.begin();
    auto it2 = arr.end(); it2--;

    while (it1 != it2)
    {
        if((it1->second + it2->second) > x) it2--;
        else if ((it1->second + it2->second) < x) it1++;
        else break;
    }
    
    if(it1 != it2){
        cout << it1->first + 1 << " " << it2->first + 1 << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }


    /* for(auto it = arr.begin(); it != arr.end(); it++)
        cout << it->first << " " << it->second << endl; */

    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    vector<pair<int,int>> arr; arr.reserve(n);
    
    int a;
    for(i=0; i<n; i++){
        cin >> a;
        arr.push_back({i,a});
    }
    sumTwoValues(arr, n, x);

    return 0;
}