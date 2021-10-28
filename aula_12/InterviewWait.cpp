//SOLVED

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

void solve(vector<int> &arr){
    deque<int> d;
    for(auto el : arr) d.push_back(el);

    int res = 0;

    while(d.front() != -1 && d.back() != -1){
        if(d.front() < d.back()){
            res += d.front();
            d.pop_front();
        }else{
            res += d.back();
            d.pop_back();
        }
    }
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {4,-1,5,2,3};
    solve(arr);
    return 0;
}
