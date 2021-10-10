/**
 *  @descripcion: Este programa fue enviado y se queda en la PRUEBA 15 (complejidad cuadrática)
*/


#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

typedef unsigned long long int ull;

const ull NMOD = 1e9 + 7;
ull N,K, xi, a, b, c, md[5000][5000], n=0, i=0;

void fill(ull i, ull N, ull xi, ull a, ull b, ull c){
    md[i][0] = xi;
    for(ull j=1; j<N; j++){
        md[i][j] = ( ( (md[i][j-1]%c) * (a%c))%c + (b%c))%c;
    }
}

void minHeighsSquaresK(){
    ull res = 0;
    for (ull i = 0; i < N; i++){
        for (ull j = 0; j < N - K + 1; j++){
            ull mini = ULLONG_MAX;
            for (ull k = j; k < j + K; k++){
                mini = min(mini, md[i][k]);
            }
            md[i][j] = mini;
        }
    }

    for (ull j = 0; j < N; j++){
        for (ull i = 0; i < N - K + 1; i++){
            ull mini = ULLONG_MAX;
            for (ull k = i; k < i + K; k++){
                mini = min(mini, md[k][j]);
            }
            md[i][j] = mini;
        }
    }

    for (ull i = 0; i < N - K + 1; i++)
        for (ull j = 0; j < N - K + 1; j++)
            res  = (res%NMOD + md[i][j]%NMOD)%NMOD;
    
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    while(n < N){
        cin >> xi >> a >> b >> c;
        fill(n, N, xi, a, b, c);
        n++;
    }

    minHeighsSquaresK();

    return 0;
}
