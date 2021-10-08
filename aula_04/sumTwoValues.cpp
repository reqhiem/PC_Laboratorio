#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;
typedef unsigned long long ull;



int n,x, i,j;

bool compare(pair<int,int> &a, pair<int,int> &b){
    return (a.second < b.second);
}

void sumTwoValues(vector<pair<int,int>> &arr, int n, int x){

    sort(arr.begin(), arr.end(), compare);

    int i=0; j=n-1;

    while (i<j)
    {
        if((arr[i].second + arr[j].second) == x) break;
        else if((arr[i].second + arr[j].second) > x) j--;
        else if ((arr[i].second + arr[j].second) < x) i++;
        
    }
    
    if(i<j){
        cout << arr[i].first + 1 << " " << arr[j].first + 1 << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    
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
