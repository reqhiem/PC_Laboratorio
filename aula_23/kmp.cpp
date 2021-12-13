#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;

/* #define MAX_N 100010
char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m;

void kmpPreprocess(){
    int i=0, j=-1; b[0] = -1;
    while( i < m ){
        while( j >= 0 && P[i] != P[j] ) j = b[j];
        i++; j++;
        b[i] = j;
    } 
}

void kmpSearch(){
    int i=0, j=0;
    while( i < n ){
        while( j >= 0 && T[i] != P[j] ) j = b[j];
        i++; j++;
        if( j == m ){
            cout << "Pattern found at index " << i-j << endl;
            j = b[j];
        }
    }
}

 */

//lps
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


int main(int argc, char const *argv[])
{
    /*
    //cin.getline(T, MAX_N);
    cin.getline(P, MAX_N);
    //n = (int)strlen(T);
    m = (int)strlen(P);
    kmpPreprocess();
    //print b
    for(int i=0; i<m; i++){
        cout << b[i] + 1<< " ";
    }
    cout << endl;
    //kmpSearch();
    */

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
