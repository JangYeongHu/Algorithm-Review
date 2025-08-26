#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	string s;
	cin >> T;
	while (T--) {
		cin >> s;
		reverse(s.begin(), s.end());
		regex re("(1+0+01|10)+");
		smatch match;
		regex_search(s, match, re);
		if (match.str().length() == s.length()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}