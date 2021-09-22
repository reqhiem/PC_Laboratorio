// 1 2 3 4 5 2 3 4 5 -1

#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> v){
    
    vector<int> buc;
    bool empty = true;


    for (int i = 1; i < v.size(); i++){
        
        int j=0;
        for(; j < i; j++){
            if(v[j] == v[i]){
                break;
            }
        }

        if(empty){    
            for(int k=j; k<i; k++){
                buc.push_back(v[k]);
            }
            empty = false;
        }


        if(!empty){
            for(int tmp = 0; tmp < buc.size(); tmp++){
                if(v[i] == buc[tmp]) i++;
                else{
                    buc.clear();
                    empty = true;
                }
            }
        }
    }
    
    for(int i=0; i<buc.size(); i++){
        cout << buc[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    for(;;){
        int a;
        cin >> a;
        
        if(a == -1) break;

        v.push_back(a); 
    }

    solve(v);

    return 0;
}
