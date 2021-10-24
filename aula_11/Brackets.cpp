#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int solve(string &S){
    stack<char> st;

    for (auto let:S){
        if(let ==  '(' || let == '[' || let == '{'){
            st.push(let);
        }else{
            if (let == ')' && st.top() == '(') st.pop();
            else if (let == ']' && st.top() == '[') st.pop();
            else if (let == '}' && st.top() == '{') st.pop();
            else return 0;
        }
    }

    return (st.empty());
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;

    cout << solve(S) << endl;
    return 0;
}
