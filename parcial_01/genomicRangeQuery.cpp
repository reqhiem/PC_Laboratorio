/**
 *  @descripcion: Este programa fue admitido por el jurado como una solución
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int>&Q){
    int N  = S.length();
    int M = P.size();

    vector<vector<int>> memo(N, vector<int>(4, 0));
    vector<int> sol(M);

    char c; c = S[0];
    if(c == 'A') memo[0][0] = 1;
    if(c == 'C') memo[0][1] = 1;
    if(c == 'G') memo[0][2] = 1;
    if(c == 'T') memo[0][3] = 1;

    for(int i=1; i<N; i++){
        c = S[i];
        memo[i][0] = (c == 'A') ? memo[i-1][0] + 1 : memo[i-1][0];
        memo[i][1] = (c == 'C') ? memo[i-1][1] + 1 : memo[i-1][1];
        memo[i][2] = (c == 'G') ? memo[i-1][2] + 1 : memo[i-1][2];
        memo[i][3] = (c == 'T') ? memo[i-1][3] + 1 : memo[i-1][3];
    }

    for(int i=0; i<M; i++){
        int j = P[i], k = Q[i];

        vector<int> aux(4);
        for(int r = 0; r<4; r++){
            int pl = (j == 0) ? 0 : memo[j-1][r];
            aux[r] = memo[k][r] - pl;
        }

        int pos = -1;
        for(int i=0; i<4; i++){
            if(aux[i] != 0){
                pos = i;
                break;
            }
        }
        sol[i] = pos+1;
    }
    return sol;
}

int main(int argc, char const *argv[]){
    string S = "CAGCCTA";
    vector<int> P = {2,5,0};
    vector<int> Q = {4,5,6};

    for(auto e : solution(S,P,Q)) cout << e  << endl;

    return 0;
}
