/**
 *  @autor: Joel Perca
 *  @problema: Implementación deL algoritmo de Knuth Morris Pratt
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;

vi lps_construct(string P){
    int m = P.size();
    vi lps(m, 0);
    int len = 0;

    int i = 1, j = 0;
    while( i < m){
        if( P[i] == P[j] ){
            lps[i] = j+1;
            i++; j++;
        }
        else if( j > 0) j = lps[j-1];
        else {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

void kmp_search(string T, string P){
    int n = T.size(), m = P.size();
    vi lps = lps_construct(P);

    int i = 0, j = 0;
    while( i < n ){
        if( T[i] == P[j] ){
            i++; j++;
        }
        else if( j > 0) j = lps[j-1];
        else i++;
        if( j == m ){
            cout << "Pattern found at index " << i-j << endl;
            j = lps[j-1];
        }
    }
}


int main(int argc, char const *argv[]){
    
    string T, P;
    //cin >> T;
    cin >> P;
    vi lcp = lps_construct(P);
    for(int i=0; i<P.size(); i++){
        cout << lcp[i] << " ";
    }
    cout << endl;
    cin >> T;
    kmp_search(T, P);

    
    return 0;
}
