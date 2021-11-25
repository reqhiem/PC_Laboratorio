/**
 *  autor: Joel Perca
 *  problema: Fibonacci Sequence de Beecrowd https://www.beecrowd.com.br/judge/en/problems/view/1701
*/


#include <iostream>
#include <vector>
//#define MOD 1000000007

using namespace std;

typedef unsigned long long int ulli;
typedef vector<ulli> vulli;

void multiply(ulli F[2][2], ulli M[2][2]);
void power(ulli F[2][2], ulli n);
 
template <class T>
void multiply(T M[2][2], T N[2][2], T y){
    T a = ((((M[0][0]%y)*(N[0][0]%y))%y)%y + (((M[0][1]%y)*(N[1][0]%y))%y)%y)%y;
    T b = ((((M[0][0]%y)*(N[0][1]%y))%y)%y + (((M[0][1]%y)*(N[1][1]%y))%y)%y)%y;
    T c = ((((M[1][0]%y)*(N[0][0]%y))%y)%y + (((M[1][1]%y)*(N[1][0]%y))%y)%y)%y;
    T d = ((((M[1][0]%y)*(N[0][1]%y))%y)%y + (((M[1][1]%y)*(N[1][1]%y))%y)%y)%y;

    N[0][0] = a;
    N[0][1] = b;
    N[1][0] = c;
    N[1][1] = d;
}

template <class T>
void power(T M[2][2], T x, T y){
    if(x == 1 || x == 0) return ;
    if(x%2==0){ //par
        power(M,x/2,y);
        multiply(M,M,y);
    }else{ //impar
        T A[2][2] = {{0%y, 1%y}, {1%y, 1%y}};
        power(M, x/2, y);
        multiply(M,M,y);
        multiply(A,M,y);
    }
}

template <class T>
T lomo_saltado_mm(T n, T m){
    if(n <= 1) return n%m;

    T M[2][2] = {{0%m, 1%m}, {1%m, 1%m}};
    power<T>(M, n-1, m);
    return M[1][1];
}


int main(int argc, char const *argv[])
{
    ulli MOD = 1000000007;
    ulli A,B,N;
    
    while(true){
        cin >> A >> B >> N;
        if(A == 0 && B == 0 && N == 0) break;
        
        ulli res = 0;
        for(ulli i=0; i<N; i++){
            res += lomo_saltado_mm(A+i,MOD)*lomo_saltado_mm(B+i,MOD);
            res %= MOD;
        }
        res %= MOD;
        cout << res << endl;
    }
    
    return 0;
}
