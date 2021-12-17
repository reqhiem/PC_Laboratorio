/**
 *  @autor: Joel Perca
 *  @problema: Bachets Game from https://open.kattis.com/problems/bachetsgame
*/

#include <iostream>
using namespace std;

int n,m;
int a[10];
bool dp[1000001];

int main(int argc, char *argv[]){
    while(cin >> n >> m){
        for(int i = 0;i < m; i++) cin >> a[i];
        
        dp[0]=false;
        for(int i = 1; i <= n; i++){
            dp[i]=false;
            
            for(int j = 0; j < m; j++)
                if(i >=a [j] && !dp[i-a[j]]){
                    dp[i]=true;
                    break;
                }
        }
        
        if(dp[n]) 
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
    }
    
    return 0;
}