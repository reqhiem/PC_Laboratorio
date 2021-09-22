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
    
    
    for(int i=0; i<n; i++){
        int aux = nums[i], memo;
        for(int j=i; j<n; j++){
            memo = (i == j) ? aux : (aux + nums[j]); aux = memo;
            cont = (memo % k == 0) ? cont + 1 : cont;
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

    cout << subarrayDivisible(nums, k) << endl;

    return 0;
}