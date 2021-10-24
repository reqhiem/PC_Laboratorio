#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void solve(string s){
    stack<int> res;
    int aux = 0;

    for(int i=0; i<s.length(); i++){
        if (s[i] == '('){
            res.push(aux);
            aux = 0;
        }
        else{
            aux = res.top() + max(2*aux, 1);
            res.pop();
        }
    }
    cout << aux << endl;
}

int main(int argc, char const *argv[])
{
    string s = "(()(()))";
    solve(s);
    return 0;
}
