#include <iostream>
#include <cmath>
using namespace std;

typedef long long llong;

const llong MS = 2e5 + 10;
llong N, Q, n, arr[MS], type, k, u, a, b;

llong _build(llong *arr, llong l, llong r, llong *t, llong i){
    if(l == r){
        t[i] = arr[l];
        return arr[l];
    }

    llong m = l + (r - l) / 2;
    t[i] = _build(arr, l,m,t,i*2 + 1) + _build(arr, m+1, r, t, i*2 + 2);
    return t[i];
}

llong *build(llong *arr, llong n){
    llong h = (llong)(ceil(log2(n)));
    llong ms = 2*(llong)pow(2, h) - 1;

    llong *t = new llong[ms];
    _build(arr, 0, n-1, t, 0);
    return t;
}

llong _query(llong *t, llong sl, llong sr, llong ql, llong qr, llong i){
    if(ql <= sl && qr >= sr){
        return t[i];
    }
    if(sr < ql || sl > qr){
        return 0;
    }
    llong m = sl + (sr - sl) / 2;
    return _query(t, sl, m, ql, qr, i*2 + 1) + _query(t, m+1, sr, ql, qr, i*2 + 2);
}

llong query(llong *t, llong n, llong l, llong r){
    return _query(t,0,n-1,l,r,0);
}

void _update(llong *t, llong sl, llong sr, llong i, llong diff, llong si){
    if(i < sl || i > sr){
        return;
    }
    t[si] += diff;
    if(sl != sr){
        llong m = sl + (sr - sl) / 2;
        _update(t, sl, m, i, diff, si*2 + 1);
        _update(t, m+1, sr, i, diff, si*2 + 2);
    }
}

void update(llong *arr, llong *t, llong n, llong i, llong v){
    llong diff = v - arr[i];
    arr[i] = v;

    _update(t, 0, n-1, i, diff, 0);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    while(n < N) cin >> arr[n++];

    llong *t= build(arr, N);
    
    while(Q--){
        cin >> type;
        if(type == 1){
            cin >> k >> u;
            update(arr, t, N, k-1, u);
        }else{
            cin >> a >> b;
            cout << query(t, N, a-1, b-1) << endl;
        }
    }

    delete [] t;
    return 0;
}
