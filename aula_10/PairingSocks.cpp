//Open Kattis Pairing Socks problem
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n =0, N, x;

void solve(stack<int> &S){
    int res = 0;
    stack<int> aux;

    while(!S.empty()){
        if(aux.empty()){
            aux.push(S.top());
            S.pop();
            res++;
        }
        else{
            if(S.top() == aux.top()){
                res++;
                aux.pop();
                S.pop();
            }
            else{
                aux.push(S.top());
                S.pop();
                res++;
            }
        }
    }
    if(aux.empty()){
        cout << res << "\n";
    }else{
        cout << "impossible \n";
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    stack<int> S;

    while(n++ < 2*N){
        cin >> x;
        S.push(x);
    }

    solve(S);

    return 0;
}
