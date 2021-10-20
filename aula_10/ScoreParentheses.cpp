#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void solve(string s){
    stack<char> st;
    stack<int> res;
    stack<int> op;

    for(int i=0; i<s.length(); i++){
        if (s[i] == '(') st.push(s[i]);
        else{
            if (op.empty()){
                res.push(1);
            } 
            else{

            }
        }
    }
    
}

int main(int argc, char const *argv[])
{
    string s = "(()(()))";
    solve(s);
    return 0;
}
