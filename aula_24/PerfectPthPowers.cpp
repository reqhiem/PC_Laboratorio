#include <iostream>
#include <cmath>
using namespace std;

double x, xx, b, r;
int p;

int main(int argc, char const *argv[])
{
    while(cin >> x){
        if (x == 0)
            break;
        xx = fabs(x);
        for(b = 2; (r=b*b) <= xx; b++){
            for(p = 2; r < xx; p++)
                r *= b;
            if (r == xx)
                if( x > 0 || p%2){
                    cout << p << endl;
                    goto done;
                }
        }
    }
    return 0;
}
