#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

//Implementacion recursiva del Knapsack problem
int knapsack(int W, vi &val, vi &wt, int n){
    //Caso base
    if (n == 0 || W == 0) return 0;

    //Si el peso del item n es mayor que el peso del knapsack W,
    //entonces no se puede agregar el item n en la solucion
    if(wt[n-1] > W) return knapsack(W, val, wt, n-1);
    //Maximo de:
    //1. Agregar el item n en la solucion
    //2. No agregar el item n en la solucion
    else
        return max(val[n-1] + knapsack(W-wt[n-1], val, wt, n-1), knapsack(W, val, wt, n-1));
}



//Implementacion con memorizacion del Knapsack problem
int knapsack_aux(int W, vi val, vi wt, int i, vvi &memo){
    if(i < 0 ) return 0;
    if(memo[i][W] != -1) return memo[i][W];
    if(wt[i] > W){
        memo[i][W] = knapsack_aux(W, val, wt, i-1, memo);
        return memo[i][W];
    }
    else{
        memo[i][W] = max(val[i] + knapsack_aux(W-wt[i], val, wt, i-1, memo), knapsack_aux(W, val, wt, i-1, memo));
        return memo[i][W];
    }   
}


int knapsack_mem(int W, vi &val, vi &wt, int n){
    //Caso base
    if (n == 0 || W == 0) return 0;

    //creamos la tabla inicializada en -1
    vvi memo(n, vi(W+1, -1));

    return knapsack_aux(W, val, wt, n-1, memo);
}

//Implemetacion Bottom Up del Knapsack problem
int knapsack_bu(int W, vi &val, vi &wt, int n){
    //creamos la tabla inicializada en -1
    vvi memo(n+1, vi(W+1, -1));
    //llenamos la tabla
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0)
                memo[i][j] = 0;
            else if(wt[i-1] <= j){
                memo[i][j] = max(val[i-1] + memo[i-1][j-wt[i-1]], memo[i-1][j]);
            }
            else{
                memo[i][j] = memo[i-1][j];
            }
        }
    }

    return memo[n][W];
}


int main(int argc, char const *argv[]){
    vi val = {60, 100, 120};
    vi wt = {10, 20, 30};
    int W = 50;
    int n = val.size();
    cout << knapsack(W, val, wt, n) << endl;
    cout << knapsack_mem(W, val, wt, n) << endl;
    cout << knapsack_bu(W, val, wt, n) << endl;
    return 0;
}
