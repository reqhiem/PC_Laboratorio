#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 17;
    cout << ((n & (n-1)) == 0) << endl;

    //(n & (n-1)) opera a nivel de bits el operador lógico AND entre un número y su menor consecutivo.
    // En el ejemplo de 17 cuya notación binaria es 10001
    // y su menor consecutivo 16 con notación bin.  10000
    //el resultado es la cadena binaria             10000 (por las reglas del algebra booleana)
    // ese resultado es 16 y comparado con 0 pues resultado FALSO.

    //otro ejemplo que podemos probar es

    n = 2; // binario 10
           // n-1 :   01
           // res :   00
    cout << ((n & (n-1)) == 0) << endl;

    //y eso sí resulta VERDAD porque 00 es 0 y eso es igual a 0
    return 0;
}
