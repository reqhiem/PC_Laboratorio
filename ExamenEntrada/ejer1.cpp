//Casos de prueba
/*

string str1 = "elanio pasado";
string str2 = "sapado laeoin";

*/


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//función que identifique si dos strings son anagramas o no
bool sonAnagramas(string str1, string str2){
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    return (str1 == str2) ? true : false;
}


int main(int argc, char const *argv[])
{
    string str1 = "hola ";
    string str2 = "l aho";

    if (sonAnagramas(str1, str2)){
        cout << "son anagramas" << endl;
    }else{
        cout << "no son anagramas" << endl;
    }
    return 0;
}
