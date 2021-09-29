#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

typedef vector<int> vi;

bool compare(int a, int b){
    return ((a*a) < (b*b));
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi arr = {-4,-3,1,2,3};

    sort(arr.begin(), arr.end(), compare);

    for(auto elem : arr) cout << elem*elem << " ";
    cout << "\n";

    return 0;
}
