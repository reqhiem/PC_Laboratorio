/**
 *  @autor: Joel Perca
 *  @problema: Growling Gears from https://open.kattis.com/problems/growlinggears
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int i, TC, N, solv;
double a,b,c, res, aux;

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> TC;
    while(TC--){
        cin >> N;
        res = -999999.0;
        solv = 0;

        for(i = 0; i < N; i++){
            cin >> a >> b >> c;
            aux =  -a*pow(b/(2*a), 2) + b*(b/(2*a)) + c;
            if(aux > res){
                res = aux;
                solv = i;
            }
        }
        cout << solv+1 << endl;
    }
    return 0;
}
