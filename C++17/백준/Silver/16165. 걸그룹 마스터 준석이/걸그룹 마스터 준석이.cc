#include <bits/stdc++.h>
using namespace std;
unordered_map<string,vector<string>> idol;
unordered_map<string, string> imap;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tn; cin >> tn;
		int t; cin >> t;
		vector<string> v;
		for (int j = 0; j < t; j++) {
			string s; cin >> s;
			v.push_back(s);
			imap[s] = tn ;
		}
		sort(v.begin(), v.end());
		idol[tn] = v;
	}

	while (m--) {
		string s; cin >> s;
		int t; cin >> t;
		if (t) {
			cout << imap[s] << "\n";
		} else {
			for (string tt : idol[s]) cout << tt << "\n";
		}
	}
}