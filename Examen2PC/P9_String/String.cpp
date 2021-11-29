/**
 *  problema: String de Beecrowd https://www.beecrowd.com.br/judge/en/problems/view/2917
*/
#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

#define INFM INT_MIN

typedef long long ll;
typedef vector<ll> vi;

int m;

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    m=0;
    while(cin>>m){
        vi arr(m*10,0);
        for(int i=0; i<m*10;i++){
            cin >> arr[i];
        }
        ll total=m*20, temp=0, res=INFM, i=0, k=0, current=0; 
        bool flag=false;
        while(i<total){
            if(k==(m*10)){ k=0;flag=true;}
            temp=temp+arr[k];

            if(current==k && flag==true)
                break;
            else{ 
                if(res<temp){
                    res=temp;
                }
            }

            if(temp<=0){ 
                if(k==(m*10)-1)
                    current=0;
                else
                    current=k+1; 
                temp=0;
            }
            i++;
            k++;
        }
        cout << res <<"\n";
    }

    return 0;
}