//casos de prueba

/*

    bitset<32> a{31};
    bitset<32> b{14};

    bitset<32> a{54};
    bitset<32> b{13};

*/

#include <iostream>
#include <bitset>
#include <cassert>

using namespace std;

int main(int argc, char const *argv[])
{  
    //aqui cambiar los casos de prueba
    bitset<32> a{31};
    bitset<32> b{14};
    //toma los numeros en binario

    auto aa = a.to_string(); //convierte a string para analizar bit por bit
    auto bb = b.to_string();

    int conta = 0;
    for(int i=aa.size()-1; i>=0; i--){ //determinamos la cantidad de unos en cada numero
        if(aa[i] != bb[i]) conta++;
    }


    cout << conta << endl;
    return 0;
}
