//SOLVED

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

void solve(string &str){
    queue<char> q;
    string res = "";
    bool isCap = false;

    for(int i=0; i<str.length(); i++){
        if(str[i] == '$'){
            while(!q.empty()){
                res += (isCap) ? toupper(q.front()) : tolower(q.front());
                q.pop();
            }
        }else if(str[i] == '@'){
            isCap = (isCap) ? false : true;
        }else{
            q.push(str[i]);
        }
    }
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    string str = "abc$d@ef$@g$";
    //cin >> str;
    solve(str);
    return 0;
}
