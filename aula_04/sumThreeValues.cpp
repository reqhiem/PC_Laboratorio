//https://cses.fi/problemset/result/2963931/
//ACCEPTED


#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pair<ll, ll>> vpll;

ll N,X;

bool compare(pll &a, pll &b){
    return (a.first < b.first);
}


void sumThreeValues(vpll& nums, ll target){
    ll n = nums.size();

    sort(nums.begin(), nums.end(), compare);
    
    ll i,j,k;
    bool flag = false;
    for(i=0; i<n; i++){
        
        j=i+1; k=n-1;
        while(j<k){
            if(((nums[j].first)+(nums[k].first)) == (target - nums[i].first)){flag = true; break;}
            else if(((nums[j].first)+(nums[k].first)) > (target - nums[i].first)) k--;
            else if(((nums[j].first)+(nums[k].first)) < (target - nums[i].first)) j++;
        }

        if(flag) break;
    }

    if(flag) cout << nums[i].second + 1 << " "  << nums[j].second + 1 << " " << nums[k].second + 1 << endl;
    else cout << "IMPOSSIBLE" << endl;
}


int main(int argc, char const *argv[])
{
    cin >> N >> X;
    vpll v(N);

    for (ll i = 0, x; i < N; i++){
        cin >> x;
        v[i] = make_pair(x, i);
    }

    sumThreeValues(v, X);

    return 0;
}
