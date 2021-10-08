/**
 *  @autor: jperca
 *  @pruebas: 

list<int> v = {5,10,10,1,2,2,50,12,12};
list<int> v = {40,12,3,8,3,2,45,40,23};


*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

void eliminarRepetido(list<int> &v){
    list<int> aux;
    for(auto it = v.begin(); it != v.end(); it++){
        bool flag = false;
        for(auto it2 = aux.begin(); it2 != aux.end(); it2++){
            if(*it == *it2){
                flag = true;
                break;
            }
        }
        if(!flag){
            aux.push_back(*it);
        }
    }

    for(auto elem : aux) cout << elem << endl;
}

int main(int argc, char const *argv[])
{
    
    list<int> v = {5,10,10,1,2,2,50,12,12};
    //list<int> v = {40,12,3,8,3,2,45,40,23};

    eliminarRepetido(v);
    return 0;
}
