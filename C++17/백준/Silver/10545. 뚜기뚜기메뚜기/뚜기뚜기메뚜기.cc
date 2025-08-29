#include <bits/stdc++.h>
using namespace std;
int pad[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int clk[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };
int ch[9];
int main() {
	for (int i = 0; i < 9; i++) cin >> ch[i];
	string s; cin >> s;
	char prv = 0;
	for (char c : s) {
		int idx = c - 'a';
		for (int i = 0; i < 9; i++) {
			if (ch[i] == pad[idx]) {
				idx = i + 1; break;
			}
		}
		if (prv == idx) cout << '#';
		for (int i = 0; i < clk[c-'a']; i++) cout << idx;
		prv = idx;
	}
	return 0;
}