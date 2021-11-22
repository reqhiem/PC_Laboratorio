#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int lengthOfLIS(vi &nums){
    if(nums.size() <= 1) return nums.size();

    vi dp(nums.size(), 1);
    int maxi = 1;
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main(int argc, char const *argv[])
{
    vi nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}
