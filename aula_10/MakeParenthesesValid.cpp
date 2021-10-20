#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void solve(string s){
    stack<char> st;
    int aux = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            if(s[i] == ')' && !st.empty()){
                st.pop();
            }else{
                aux++;
            }
        }
    }
    cout << aux + st.size() << endl;
}

int main(int argc, char const *argv[])
{
    string s = "())";
    solve(s);
    return 0;
}
