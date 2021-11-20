//SOLVED

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

void solve(string &str){
    deque<char> d;

    string res = "";

    for(int i=0; i<str.length(); i++){
        if(str[i] == '#') d.pop_back();
        else d.push_back(str[i]);
    }
    for(auto it = d.begin(); it != d.end(); it++)
        res += *it;
    
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    string str = "abc#de##f#ghi#jklmn#op#"; //Expected ouptut: abghjklmo
    solve(str);
    return 0;
}
