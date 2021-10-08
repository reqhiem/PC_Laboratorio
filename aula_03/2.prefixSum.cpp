/**
 *  @autor: jperca
 *  @descripcion: PREFIX SUM. Cálculo rápido de sumas de elementos en un determinado rango 
 *  @pruebas:

5
1 2 3 4 5

6
6 7 12 2 4 5 

*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef unsigned long long int ull;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    vi A, B; B.push_back(0);

    while(n--){
        cin >> x;
        A.push_back(x);
        B.push_back(B.back() + x);
    }

    //imprimir el arreglo con la suma de prefijos
    for(auto el : B) cout << el << " ";
    cout << endl;

    return 0;
}