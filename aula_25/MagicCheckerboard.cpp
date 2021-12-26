/**
 * @autor: Joel Perca
 * @problema: Magic Checkerboard from https://open.kattis.com/problems/checkerboard
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


ll heightIsOne(vector<vector<ll>>& board){
    ll s = 0;
    for(ll i=0;i<board[0].size();i++){
        if(board[0][i] == 0){
            if(i == 0)
                board[0][i] = 1;
            else
                board[0][i] = board[0][i-1] + 1;
        }
        else{
            if(i!=0 && board[0][i] <= board[0][i-1])
                return -1;
        }
        s+=board[0][i];
    }
    return s;
}

ll widthIsOne(vector<vector<ll>>& board){
    ll s = 0;
    for(ll i=0;i<board.size();i++){
        if(board[i][0] == 0){
            if(i == 0)
                board[i][0] = 1;
            else
                board[i][0] = board[i-1][0] + 1;
        }
        else{
            if(i!=0 && board[i][0] <= board[i-1][0])
                return -1;
        }
        s+=board[i][0];
    }
    return s;
}

void assignTop(vector<vector<ll>>& board, ll r, ll c, ll& val){
    if(r == 0){
        val = 0;
    }
    else{
        val = board[r-1][c];
    }
}

void assignLeft(vector<vector<ll>>& board, ll r, ll c, ll& val){
    if(c == 0){
        val = 0;
    }
    else{
        val = board[r][c-1];
    }
}

ll findMinSumIfEvenEven(vector<vector<ll>> board){
    ll s = 0;
    ll t = 0;
    ll l = 0;
    for(ll i=0;i<board.size();i++){
        for(ll j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            if(board[i][j] == 0){
                board[i][j] = max(t, l) + 1;
                if(board[i][j] % 2 != i%2){
                    board[i][j]++;
                }
            }
            else if( i%2!=board[i][j]%2 
                || board[i][j] <= l || board[i][j] <= t){
                    return LLONG_MAX;
            }
            s += board[i][j];
        }
    }
    return s;
}

ll findMinSumIfOddEven(vector<vector<ll>> board){
    ll s = 0;
    ll t = 0;
    ll l = 0;
    for(ll i=0;i<board.size();i++){
        for(ll j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            if(board[i][j] == 0){
                board[i][j] = max(t, l) + 1;
                if(board[i][j]%2 == j%2){
                    board[i][j]++;
                }
            }
            else if( j%2==board[i][j]%2 
                || board[i][j] <= l || board[i][j] <= t){
                    return LLONG_MAX;
            }
            s += board[i][j];
        }
    }
    return s;
}

ll findMinSumIfEvenOdd(vector<vector<ll>> board){
    ll s = 0;
    ll t = 0;
    ll l = 0;
    for(ll i=0;i<board.size();i++){
        for(ll j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            if(board[i][j] == 0){
                board[i][j] = max(t, l) + 1;
                if(board[i][j] % 2 != j%2){
                    board[i][j]++;
                }
            }
            else if( j%2!=board[i][j]%2  
                || board[i][j] <= l || board[i][j] <= t){
                    return LLONG_MAX;
            }
            s += board[i][j];
        }
    }
    return s;
}

ll findMinSumIfOddOdd(vector<vector<ll>>& board){
    if(board[0][0] == 0){
        board[0][0] = 1;
    }
    ll s = 0;
    ll t = 0;
    ll l = 0;
    for(ll i=0;i<board.size();i++){
        for(ll j=0;j<board[0].size();j++){
            assignTop(board, i, j, t);
            assignLeft(board, i, j, l);
            if(board[i][j] == 0){
                board[i][j] = max(t, l) + 1;
                if(board[i][j] % 2 == i%2){
                    board[i][j]++;
                }
            }
            else if( i%2==board[i][j]%2  
                || board[i][j] <= l || board[i][j] <= t){
                    return LLONG_MAX;
            }
            s += board[i][j];
        }
    }
    return s;
}

int main(){
    ll r = 0, c = 0;
    cin >> r >> c;
    vector<vector<ll>> board(r,vector<ll>(c));
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cin >> board[i][j];
        }
    }
    if(r==1)
        cout << heightIsOne(board);
    else if(c == 1)
        cout << widthIsOne(board);
    else{
        ll a = min(findMinSumIfEvenEven(board), findMinSumIfEvenOdd(board));
        ll b = min(findMinSumIfOddOdd(board), findMinSumIfOddEven(board));
        ll c = min(a, b);
        if(c == LLONG_MAX){
            cout << -1;
        }
        else{
            cout << c;
        }
    }
}