#include <bits/stdc++.h>
using namespace std;
string s = "yhesocvxduiglbkrztnwjpfmaq";
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	string a;
	getline(cin, a);
	for(int i = 0; i < t; i++) {
		getline(cin, a);
		cout << "Case #" << i+1 << ": ";
		for (char c : a) {
			if (c == ' ') cout << c;
			else cout << s[c - 97];
		}
		cout << "\n";
	}

	return 0;
}