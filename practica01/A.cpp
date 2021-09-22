#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    int C, a = -99, b= -99, tmp = -99;
    cin >> C;

    while (C--)
    {
        int n;
        cin >> n;

        if (n > a){
            b = a;
            tmp = a;
            a = n;
        }
        if(n > b && n < a) b = n;
    }

    cout << a*b << endl;
    



    return 0;
}
