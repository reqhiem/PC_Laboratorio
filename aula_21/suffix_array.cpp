#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 100010
char T[MAX_N]; //inpput string
int n;
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
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

int main(){
    cin.getline(T, MAX_N);
    n = (int)strlen(T);
    T[n++] = '$';
    constructSA();
    for (int i = 1; i < n; i++){
        cout << SA[i] << " " << T + SA[i] << endl;
    }
}