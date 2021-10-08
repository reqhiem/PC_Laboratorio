#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, k;
ll arr[200005];
multiset<ll> der;
multiset<ll> izq;
ll qIzq, qDer;

void insertar(ll val){
	ll a = *izq.rbegin();
	if(a < val){
		der.insert(val); qDer += val;
		if(der.size() > k/2){
			ll moving = *der.begin();
			izq.insert(moving); qIzq += moving;
			der.erase(der.find(moving)); qDer -= moving;
		}
	}
	else{
		izq.insert(val); qIzq += val;
		if(izq.size() > (k + 1)/2){
			ll moving = *izq.rbegin();
			der.insert(*izq.rbegin()); qDer += moving;
			izq.erase(izq.find(*izq.rbegin())); qIzq -= moving;
		}
	}
}

void borrar(ll val){
	if(der.find(val) != der.end()) der.erase(der.find(val)), qDer -= val;
	else izq.erase(izq.find(val)), qIzq -= val;
	if(izq.empty()){
		ll moving = *der.begin();
		izq.insert(*der.begin()); qIzq += moving;
		der.erase(der.find(*der.begin())); qDer -= moving;
	}
}

ll med(){ return (k%2 == 0) ? 0 : (*izq.rbegin()); }


void slidingCost(){
    izq.insert(arr[0]); qIzq += arr[0];
	for(ll i = 1; i < k; i++) insertar(arr[i]);
	cout << qDer - qIzq + med(); if(n!=1) cout << " ";
	for(ll i = k; i < n; i++){
		if(k == 1){
			insertar(arr[i]);
			borrar(arr[i - k]);
		}
		else{
			borrar(arr[i - k]);
			insertar(arr[i]);
		}
		cout << qDer - qIzq + med(); if(i != n -1) cout << " ";
	}
	cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> k;
	for(ll i = 0; i < n; i++) cin >> arr[i];
    
	slidingCost();
}