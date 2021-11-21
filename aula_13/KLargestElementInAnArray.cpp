#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()-k];
}

int main(int argc, char const *argv[])
{
    vi nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}
