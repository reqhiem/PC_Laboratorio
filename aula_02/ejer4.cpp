/**
 *  @autor: jperca
 *  @pruebas: 

{4,5,6,1,3}
stack<int> s;



*/

#include <iostream>
#include <stack>

using namespace std;



void sortStack(stack<int> &s){
    stack<int> aux = s;
    while (!s.empty())
    {
        int num = s.top(); s.pop();
        while(!aux.empty() && aux.top() < num){
            s.push(aux.top());
            aux.pop();
        }
        aux.push(num);
    }
    while(!aux.empty()){
        s.push(aux.top()); aux.pop();
    }
    

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    
}

int main(int argc, char const *argv[])
{
    stack<int> s;
    s.push(4); 
    s.push(5); 
    s.push(6); 
    s.push(1); 
    s.push(3);
    
    sortStack(s);

    return 0;
}
