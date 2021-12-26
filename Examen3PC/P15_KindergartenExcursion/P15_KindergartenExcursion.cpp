/**
 * @autor: Joel Perca
 * @problema: Kindergarten Excursion from https://open.kattis.com/problems/excursion
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

string str;
ll res, val, i;

int main(int argc, char const *argv[])
{
    vector<ll> digits = {0,0,0};
    cin >> str;
    res = 0;
    for(auto &c : str){
        val  = c - '0';
        for(i = val + 1; i < 3; i++){
            res += digits[i];
        }
        digits[val]++;
    }
    cout << res << endl;
    return 0;
}
