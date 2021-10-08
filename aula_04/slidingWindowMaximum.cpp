//https://leetcode.com/problems/sliding-window-maximum/submissions/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void slidingWindowMaximum1(vector<int> &nums, int k) {
    int n=nums.size();
    
    int *left = new int[n];
    int *right = new int[n];

    left[0] = nums[0];
    for(int i=1; i<n; i++){
        if(i%k == 0) left[i] = nums[i];
        else left[i] = max(left[i-1], nums[i]);
    }

    right[n-1] = nums[n-1];
    for(int i=1; i<n; i++){
        int j = n-1-i;
        
        if((j+1)%k == 0) right[j] = nums[j];
        else right[j] = max(right[j+1], nums[j]);
    }

    vector<int> res(n-k+1);

    for(int i=0; i<n-k+1; i++){
        res[i] = max(left[i+k-1], right[i]);
    }

    

    for(auto elem: res) cout << elem << " ";
    cout << endl;

    delete [] left;
    delete [] right;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> arr = {1,3,3,2,2,5};
    int k = 3;

    //vector<int> arr = {4,-2};
    //int k = 2;

    slidingWindowMaximum1(arr, k);
    return 0;
}
