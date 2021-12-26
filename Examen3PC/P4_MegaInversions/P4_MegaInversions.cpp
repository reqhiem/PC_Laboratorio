/**
 * @autor: Joel Perca
 * @problema: Mega Inversions from https://open.kattis.com/problems/megainversions
*/

#include <cstring>
#include <iostream>
using namespace std;

#define N 10000000
typedef long long ll;


ll r[N+1],q[N+1],K,ts,cs,n,a[N];

void update_tree( ll *t, unsigned int i, ll dt ) {
	for (;i <= n; t[i] += dt, i += ((i) & (~(i)+1)) );
}

ll prefix_sum( ll *t, unsigned int i ) {
	ll w = 0;
	for (;i; w += t[i], i -= ((i) & (~(i)+1)) );
	return w;
}

int main(int argc, char const *argv[]) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int j,k;
	ll w;

    cin >> n;
	memset(r,0,sizeof(r));
	memset(q,0,sizeof(q));

	for ( K = 0; (1UL << K) < n; ++K );
	for ( j = 0; j < n; ++j ) {
        cin >> a[j];
		update_tree( q, j+1, prefix_sum(r,n) - prefix_sum(r,a[j]) );
		update_tree( r, a[j], 1 );
	}

	memset( r, 0, sizeof(r) );
	for ( w = 0, k = 0; k < n; ++k ) {
		w += prefix_sum(r,n) - prefix_sum(r,a[k]);
		update_tree( r, a[k], prefix_sum(q,k+1)-prefix_sum(q,k) );
	}
    
    cout << w << endl;
	return 0;
}

