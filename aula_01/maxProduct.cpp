/**
 *  @autor: jperca
 *  @descripcion: Dada una secuencia de n números no negativos y mayores que cero.
 *                El objetivo es encontrar el mayor número que se pueda obtener 
 *                multiplicando dos números de esta secuencia.
 *  @pruebas:

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
    //inicializamos las variables
    int C, a = -99999, b= -99999, tmp = -99999;
    cin >> C;

    while (C--)
    {
        //captamos la entrada
        int n;
        cin >> n;

        if (n > a){ //si es mayor actualizamos
            b = a;
            tmp = a;
            a = n;
        }
        if(n > b && n < a) b = n;
    }

    cout << a*b << endl;

    return 0;
}
