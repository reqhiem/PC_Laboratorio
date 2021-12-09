/**
 *  @autor: Joel Perca
 *  @problema: Repeated Substrings from https://open.kattis.com/submissions/8148699
 *  @estado: Enviado al jurado TIME LIMIT EXCEEDED
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 100010
char T[MAX_N]; //inpput string
int n;
int RA[MAX_N], tempRA[MAX_N]; 
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int LCP[MAX_N]; // longest common prefix array
int c[MAX_N]; //for counting/radix sort


void countingSort(int k){
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++){
        c[i + k < n ? RA[i + k] : 0]++;
    }
    for (i = sum = 0; i < maxi; i++){
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; i++){
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    }
    for (i = 0; i < n; i++){
        SA[i] = tempSA[i];
    }
}

void constructSA(){
    int i,k,r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1){
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++){
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        }
        for (i = 0; i < n; i++){
            RA[i] = tempRA[i];
        }
        if (RA[SA[n-1]] == n-1) break; 
    }
    
}

void constructLCP(){
    int i,j,k,aux;
    LCP[1] = 0;
    for(i=2; i<n;i++){
        j = SA[i-1];
        k = SA[i];
        aux = 0;
        while(T[j+aux] == T[k+aux]){
            aux++;
        }
        LCP[i] = aux;
    }
}

int main(){
    int TC;
    cin >> TC;
    cin.ignore();
    while(TC--){
        cin.getline(T, MAX_N);
        n = (int)strlen(T);
        T[n++] = '$';
        constructSA();
        constructLCP();
        int res = 0;
        for(int i=2; i<n; i++){
            if(LCP[i] > LCP[i-1])
                res += LCP[i] - LCP[i-1];
        }
        cout << res << endl;
    }
}