/**
 *  @autor: jperca
*/

/* Para las pruebas

3
1 2 3

10
8 1 6 3 4 10 3 9 14 2

*/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    //declarar e inicializar las variables
    int N, a, b= -99999;
    cin >> N;
    cin >> a; N--;
    
    //a medida que se recibe los datos
    while (N--)
    {
        int x;
        cin >> x;
        
        //actualizamos el máximo y su predecesor
        if (x > a){
            b = a;
            a = x;
        }
        if(x > b && x < a) b = x;
    }

    //imprimir el resultado
    cout << a*b << endl;

    return 0;
}
