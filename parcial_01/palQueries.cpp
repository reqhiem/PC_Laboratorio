#include <iostream>
using namespace std;

int N,M, i=0, t, k, b;
char s[200005], bc;


void check(int k, int b){
    int mid = (k+b)/2;
    bool flag = true;
    while(k <= mid){
        if(s[k++] != s[b--]){
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;
    cin >> s;

    while(i++ < M){
        cin >> t;
        if(t == 1){
            cin >> k >> bc;
            s[k-1] = bc;
        }else if(t == 2){
            cin >> k >> b;
            check(k-1, b-1);
        }
    }

    return 0;
}
