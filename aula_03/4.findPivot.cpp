/**
 *  @autor: jperca
 *  @descripcion: Subarray Sums Divisible by K.
 *  @pruebas:

vi nums = {4,5,0,-2,-3,1};
vi nums = {1,7,3,6,5,6};
vi nums = {1,2,3};

*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vv;
typedef unsigned long long int ull;

int subarrayDivisible(vi &nums, int k){
    int cont = 0, n = nums.size();
    int aux, memo;
    for(int i=0; i<n; i++){
        aux = nums[i];
        for(int j=i; j<n; j++){
            memo = (i == j) ? aux : (aux + nums[j]); aux = memo;
            cont = (memo % k == 0) ? cont + 1 : cont;
        }
    }
    return cont;
}

//suma de prefijos
int subarrayDivisible1(vi &nums, int k){
    int n = nums.size();
    vector<int> ps(n+1); ps[0] = 0;
    for(int i=1; i<n+1; i++){
        ps[i] = ps[i-1] + nums[i-1];
    }

    int cont = 0;
    for(int i=1; i<n+1; i++){
        for(int j=i; j<n+1; j++){
            if( (ps[j] - ps[i-1]) % k == 0) cont++;
        }
    }

    return cont;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //aqui cambie las pruebas
    vi nums = {4,5,0,-2,-3,1};
    int k = 5;

    cout << subarrayDivisible1(nums, k) << endl;

    return 0;
}