#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	string s;
	cin >> T;
	while (T-- > 0) {
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