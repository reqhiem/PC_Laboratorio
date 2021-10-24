#include <iostream>
#include <set>
using namespace std;

int N, n=0, x;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multiset<int, less<int>> even;
    multiset<int, greater<int>> odd;

    cin >> N;
    while(n++ < N){
        cin >> x;
        if(x%2 == 0)
            even.insert(x);
        else
            odd.insert(x);
    }

    for( auto it = even.begin(); it != even.end(); it++ )
        cout << *it << endl;
    
    for( auto it = odd.begin(); it != odd.end(); it++ )
        cout << *it << endl;

    return 0;
}
