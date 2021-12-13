#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;

#define MAX_N 100010
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
            cout <<  i-j  << " ";
            j = b[j];
        }
    }
}

int main(int argc, char const *argv[])
{
    while(true){
        cin.getline(P, MAX_N);
        m = strlen(P);
        cin.getline(T, MAX_N);
        n = strlen(T);
        kmpPreprocess();
        kmpSearch(); cout << "\n";
    }
    return 0;
}
