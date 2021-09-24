#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vv;
typedef unsigned long long int ull;


int subarraySum(vi &nums, int k){
    int res = 0, sum = 0, n = nums.size();
    unordered_map<int, int> mp{{0, 1}};
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        res += mp[sum - k];
        mp[sum]++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //aqui cambie las pruebas
    vi nums = {1,2,3};
    int k = 3;

    cout << subarraySum(nums, k) << endl;

    return 0;
}