#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> &A, vector<int> &B){
    int N = A.size();
    stack<int> s;
    int aux = N;
    
    for(int i=0; i<N; i++){
        if(B[i] == 1)
            s.push(A[i]);
        else{
            while(!s.empty()){
                if(s.top() > A[i]){
                    aux--;
                    break;
                }else if(s.top() < A[i]){
                    aux--;
                    s.pop();
                }
            }
        }
    }
    
    return aux;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {4,3,2,1,5};
    vector<int> B = {0,1,0,0,0};

    cout << solution(A,B) << endl;

    return 0;
}
