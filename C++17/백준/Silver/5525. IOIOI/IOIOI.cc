#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	string s;
	cin >> n >> m;
	n = n * 2 + 1;
	cin >> s;
	int cnt = 0,res = 0;
	bool sta = 0;
	for (char c : s) {
		if (c == 'I') {
			if (sta == 1) {
				res += (cnt - n) >= 0 ? (cnt - n) / 2 + 1 : 0;
				cnt = 1;
			}
			else {
				cnt++;
				sta = 1;
			}
		}
		else {
			if(sta == 0) {
				res += (cnt - n) >= 0 ? (cnt - n) / 2 + 1 : 0;
				cnt = 0;
			}
			else {
				cnt++;
				sta = 0;
			}
		}
	}
	res += (cnt - n) >= 0 ? (cnt - n) / 2 + 1 : 0;
	cout << res;
}