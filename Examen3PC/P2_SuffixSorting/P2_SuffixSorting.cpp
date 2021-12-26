/**
 * @autor: Joel Perca
 * @problema: Suffix Sorting from https://open.kattis.com/problems/suffixsorting
*/


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 100005

typedef long long ll;


string txt;
ll N=0,x=0;
ll n=0,t=0,ans=0;
ll SA[MAX_N];
ll tmp[MAX_N],pos[MAX_N];

bool cmp(ll i,ll j){
    if(pos[i] != pos[j]) 
        return (pos[i] < pos[j]);
    i += t;
    j += t;
    if(i<n && j<n)
        return (pos[i]<pos[j]);
    return (i > j);
}

void constructSA(){
    for(ll i=0; i<n;i++){
        SA[i]=i;
        pos[i]=txt[i];
    }
    for(t=1; t<2*n+1; t*=2){
        sort(SA,SA+n,cmp);
        for(ll i=0; i<n-1;i++){
            tmp[i+1]=tmp[i];
            if(cmp(SA[i],SA[i+1])) tmp[i+1]++;
        }
        for(ll i=0; i<n;i++){
            pos[SA[i]]=tmp[i];
        }
        if(tmp[n-1]==n-1) break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(getline(cin,txt)){
        n=txt.size();
        constructSA();

        cin>>N;
        while(N--){
            cin >> x;
            cout << SA[x] << " ";
        }
        cout << "\n";

        cin.ignore();
    }
    return 0;
}