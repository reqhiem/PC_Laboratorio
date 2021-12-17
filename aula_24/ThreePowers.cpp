/**
 *  @autor: Joel Perca
 *  @problema: Three Powers from https://open.kattis.com/problems/threepowers
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int n, first, r, p;

int main(int argc, char const *argv[]){
    while(true){
        cin >> n;
        if(n == 0) break;

        --n;
        cout << "{";

        p = 0;
        first = 1;
        while(n > 0){
            r = n % 2;
            if (r == 1){
                if (first == 0)
                    cout << ", ";
                else
                    cout << " ";
                first = 0;
                cout << (int)pow(3, p);
            }
            n = n/2;
            p++;
        }
        cout << " }" << endl;
    }

    return 0;
}
