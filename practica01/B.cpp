/**
 *  @autor: jperca
 *  @descripcion: Dada una secuencia de elementos en un flujo de datos determinar si existen bucles
 *                El objetivo es encontrar la secuencia que corresponde al bucle. 
 *  @pruebas:

1 2 3 4 5 2 3 4 5 2 3 4 5 2 -1

1 2 3 4 5 6 3 7 8 9 10 11 8 9 10 11 8 9 10 11 8 -1

1 2 3 4 5 6 7 8 9 6 5 4 10 11 3 4 5 6 7 8 9 6 5 4 10 11 3 -1

*/

// 

#include <iostream>
#include <vector>
using namespace std;

//determinar el bucle en un vector de enteros
void findBucle(vector<int> v){
    
    vector<int> buc;
    bool empty = true;

    //iteramos en el vector
    for (int i = 1; i < v.size(); i++){
        
        int j=0;
        for(; j < i; j++){
            if(v[j] == v[i]){
                break;
            }
        }

        if(empty){    
            for(int k=j; k<i; k++){
                buc.push_back(v[k]);
            }
            empty = false;
        }


        if(!empty){
            for(int tmp = 0; tmp < buc.size(); tmp++){
                if(v[i] == buc[tmp]) i++;
                else{
                    buc.clear();
                    empty = true;
                }
            }
        }
    }
    
    //imprimir el bucle
    for(int i=0; i<buc.size(); i++){
        cout << buc[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    for(;;){
        int a;
        cin >> a;
        
        if(a == -1) break;

        v.push_back(a); 
    }

    findBucle(v);

    return 0;
}
