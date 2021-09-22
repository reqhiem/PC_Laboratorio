/**
 *  @autor: jperca
 *  @pruebas: 
 * 
    vector<int> A = {2,4,6};
    vector<int> B = {1,5,7};

    vector<int> A = {2,4,6,10,18};
    vector<int> B = {1,5,7};

    vector<int> A = {2,4,6,10,18};
    vector<int> B = {1,5,7,89,123,200,1000};

*/

#include <iostream>
#include <vector>
using namespace std;

//la funcion mezcla dos vectores corservando el orden de precedencia
// y devuelve otro vector
vector<int> mezclar(vector<int> &A, vector<int> &B){
    int n = A.size();
    int m = B.size();
    vector<int> res(n+m);
    
    int k=0, i=0, j=0;
    while (k < (n+m))
    {
        if(i<n && A[i] < B[j]) res[k++] = A[i++];
        if(i>=n) res[k++] = B[j++];

        if(j<m && B[j] < A[i]) res[k++] = B[j++];
        if(j>=m) res[k++] = A[i++];
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {2,4,6,10,18};
    vector<int> B = {1,5,7,89,123,200,1000};

    //llamada a la funcion mezclar
    vector<int> res = mezclar(A,B);
    for(auto elem : res) cout << elem << " ";
    cout << endl;

    return 0;
}
