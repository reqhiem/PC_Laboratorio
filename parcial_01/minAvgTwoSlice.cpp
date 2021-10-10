/**
 *  @descripcion: Este programa fue admitido por el jurado como una solución
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<int> &A){
    int N = A.size();
    double minProm = (A[0] + A[1]) / 2;
    int minPos = 0;
    //dos en dos
    for (int i = 0; i < N - 1; i++){
        double prom = (A[i] + A[i+1])/2.0;
        if (prom < minProm){
            minProm = prom;
            minPos = i;
        }
    }
    //tres en tres
    for (int i = 0; i < N - 2; i++){
        double prom = (A[i] + A[i+1] + A[i+2])/3.0;
        if (prom < minProm){
            minProm = prom;
            minPos = i;
        }
    }
    
    return minPos;
}


int main(int argc, char const *argv[])
{
    vector<int> A = {4,2,2,5,1,5,8};
    cout << solve(A) << endl;
    
    return 0;
}
