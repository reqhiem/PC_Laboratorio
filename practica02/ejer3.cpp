
/**
 *  @autor: jperca
 *  @descripcion: FIND PIVOT INDEX. Return the leftmost pivot index. If no such index exists, return -1.
 *  @pruebas:

int A[] = {2,1,-1};
int A[] = {1,7,3,6,5,6};

*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef unsigned long long int ull;

int findPivot(int *B, int n){
    int i = 0;
    for(; i<n+1; i++){
        if(B[i-1] == B[n] - B[i]) break;
    }
    return i-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //aqui cambie las pruebas
    int A[] = {1,2,3};


    int n = sizeof(A)/sizeof(A[0]);
    int *B = new int[n+1]; B[0] = 0;
    for(int i=0; i<n; i++){
        B[i+1] = B[i] + A[i];
    }

    int k = findPivot(B,n);

    if(k < n) cout << "The pivot index is: " << k << "\n";
    else cout << "-1" << endl; 
    delete [] B;
    return 0;
}