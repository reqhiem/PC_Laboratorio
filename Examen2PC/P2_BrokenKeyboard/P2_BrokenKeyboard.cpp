/**
 *  autor: Joel Perca
 *  problema: Broken Keyboard de BeeCrowd https://www.beecrowd.com.br/judge/en/problems/view/1642
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

vi tmp;

void brokenKeyboard(string &str, int m){
    tmp.assign(256, 0);
        
    int last = 0, act = 0;
    int ans = 0;
    for (int i=0; i<str.length(); i++){
        int c = str[i];
        if (tmp[c]++ == 0)
            act++;
        while (act > m){
            int cc = str[last];
            tmp[cc]--;
            if (tmp[cc] == 0)
                act--;
            last++;
        }
        int curr = i - last + 1;
        if (curr > ans)
            ans = curr;
    }
    cout << ans << endl;
}

int main(int argc, char **argv){
	int m;
	while (true){
        cin >> m >> ws;
		if (m == 0)
			break;
		
        string line;
		getline(cin, line);
        brokenKeyboard(line, m);        
	}
	return 0;
}