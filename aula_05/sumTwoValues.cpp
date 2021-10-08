#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef unordered_map<int, int> hii;

vi twoSum(vi& nums, int target){
    hii tmp;
    for(int i = 0; i < nums.size(); i++){
        if(tmp.count(target - nums[i])){
            return {tmp[target - nums[i]], i};
        }
        tmp[nums[i]] = i;
    }
    return {-1, -1};
}


int main(int argc, char const *argv[])
{
    vi nums = {2, 7, 11, 15};
    int target = 9;

    vi result = twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
