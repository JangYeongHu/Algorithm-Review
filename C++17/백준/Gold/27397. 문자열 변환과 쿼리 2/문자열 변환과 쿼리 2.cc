#include <bits/stdc++.h>
using namespace std;

string s;
unordered_map<char, char> um;

int check() {
	int mx = 1,now = 1;
	for (int i = 1; i < s.length(); i++) {
		if (um[s[i]] == um[s[i - 1]]) now++;
		else now = 1;
		mx = max(now, mx);
	}
	return mx;
}

void change(char a,char b) {
	for (auto& [k, v] : um) {
		if (v == a) {
			v = b;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> s >> n;
	for (char c : s) um[c] = c;

	while (n--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			char i1, i2; cin >> i1 >> i2;
			change(i1,i2);
		}
		else {
			cout << check() << "\n";
		}
	}
}