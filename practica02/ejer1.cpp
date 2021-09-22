/**
 *  @autor: jperca
 *  @decripcion: Write a single integer to output, denoting how many integers ti are divisible by k.
 *  @pruebas:



*/

#include <iostream>

using namespace std;
int n,k,x, cont = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> k;

    while(n--){
        cin >> x;
        cont = (x % k == 0) ? cont + 1: cont;
    }

    cout << cont << "\n";

}