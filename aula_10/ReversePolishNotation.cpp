#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int solve(vector<string> &tokens){
    stack<string> pilha;
    for(int i = 0; i < tokens.size(); i++){
        string op1 = pilha.top();
        pilha.pop();
        string op2 = pilha.top();
        pilha.pop();
        if(tokens[i] == "+"){
            string result = to_string(stoi(op1) + stoi(op2));
            pilha.push(result);
        }
        else if(tokens[i] == "-"){
            string result = to_string(stoi(op2) - stoi(op1));
            pilha.push(result);
        }
        else if(tokens[i] == "*"){
            string result = to_string(stoi(op1) * stoi(op2));
            pilha.push(result);
        }
        else if(tokens[i] == "/"){
            string result = to_string(stoi(op2) / stoi(op1));
            pilha.push(result);
        }
        else{
            pilha.push(tokens[i]);
        }
    }
    return stoi(pilha.top());
}


int main(int argc, char const *argv[]){
    vector<string> v = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << solve(v) << endl;
    return 0;
}
