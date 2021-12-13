/**
 *  problema: Suffix Array Re-construction from https://open.kattis.com/problems/suffixarrayreconstruction
*/

#include <iostream>
#include <string>

using namespace std;

void solveCase(int &len, int &numSuff){
    int pos;
	string word, suff;
    word = "";
    for (int i = 0; i < len; i++) word += "*";

    bool flag = true;
    for (int i = 0; i < numSuff; i++) {
        cin >> pos >> suff;
        pos--;
        for (int j = 0; j < suff.size(); j++) {
            if (suff[j] == '*') {
                break;
            } else if (word[j + pos] == '*' || word[j + pos] == suff[j]) {
                word[j + pos] = suff[j];
            } else {
                flag = false;
                break;
            }
        }
        for (int j = 0; j < suff.size(); j++) {
            if (suff[suff.size() - j - 1] == '*') {
                break;
            } else if (word[len - j - 1] == '*' || word[len - j - 1] == suff[suff.size() - j - 1]) {
                word[len - j - 1] = suff[suff.size() - j - 1];
            } else {
                flag = false;
                break;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        if (word[i] == '*') {
            flag = false;
        }
    }
    if (flag) {
        cout << word << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(int argc, char **argv) {
	int numCases;
	cin >> numCases;

	while (numCases--) {
		int len, numSuff;

		cin >> len >> numSuff;
		solveCase(len, numSuff);
	}
	return 0;
}
