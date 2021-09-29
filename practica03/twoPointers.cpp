#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef vector<int> vi;

void twPointers(vi &arr, int target){
    //auto p = arr.begin();
    //auto q = arr.end(); q--;

    int p=0, q=arr.size()-1;

    while(p < q){
        if((arr[p] + arr[q]) > target) q--;
        else if ((arr[p] + arr[q]) < target) p++;
        else break;
    }

    if(q != p)
        cout << "[" << p << "," << q << "] positions" << endl; 
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //vi a = {1,2,7,9,11,15};
    //int target = 11;

    vi a = {-1,1,2,3,5};
    int target = 5;

    twPointers(a, target);

    return 0;
}
