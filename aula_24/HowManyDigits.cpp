/**
 *  @autor: Joel Perca
 *  @problema: How Many Digits? from https://open.kattis.com/problems/howmanydigits
*/

#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

#define EPS  2.7182818284590452353602
#define PI  3.1415926535897932384626

typedef long long int ll;

int num;
long double aux;

ll cantDigits2(int &n){
    
    if(n <= 1){
        return 1;
    }
    
    aux = 0;
    for(int i=1; i<=n; i++){
        aux += log10(i);
    }

    return (ll)floor(aux) + 1;
}

long long cantDigits(int n){
    if (n <= 1)
        return 1;
    long double x = ((n * log10(n / EPS) + log10(2 * PI * n) / 2.0));
 
    return floor(x) + 1;
}


int main(int argc, char const *argv[])
{
    unordered_map <ll, ll> mp;

    while(cin >> num){
        if (mp[num]){
            cout << mp[num] << endl;
        }
        else{
            mp[num] = cantDigits(num);
            cout << mp[num] << endl;
        }
    }
    return 0;
}
