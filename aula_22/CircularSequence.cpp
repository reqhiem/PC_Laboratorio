/**
 *  problema: Circular Sequence from https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=4459
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

int tc;
string seq, first, second;

int main(int argc, char** argv) { 
    cin >> tc;
	while(tc--){
        cin >> seq;
		
        int len = seq.length();
		vs store;
		store.push_back(seq);

		for(int i=1; i < len; i++){
			first = seq.substr(i);
			second = seq.substr(0,i);
			store.push_back(first+second);
		}
		sort(store.begin(),store.end());
		
        cout << store[0] << endl;
	}
	return 0;
}