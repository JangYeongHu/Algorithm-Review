#include <bits/stdc++.h>
using namespace std;
int dp[51];
string sen;
int get(int idx, string str) {
	if (idx < str.size() - 1) return -1;

	unordered_map<char, int> A, B;

	for (char c : str) A[c]++;
	for (int i = idx-str.size()+1; i <= idx; i++) B[sen[i]]++;

	if (A != B) return -1;

	int res = 0;
	for (int i = 0; i < str.size(); i++) {
		if (sen[idx - str.size() + 1 + i] != str[i]) res++;
	}
	return res;
}

int main() {
	cin >> sen;
	int n; cin >> n;
	vector<string> sss;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		sss.push_back(t);
	}
	dp[0] = 0;
	for (int i = 1; i <= sen.size(); i++) {
		dp[i] = 1 << 29;
		for (string s : sss) {
			int len = s.size();
			if (i < len) continue;
			int res = get(i - 1, s);
			if (res == -1) continue;
			dp[i] = min(dp[i], dp[i - len] + res);
		}
	}
	if (dp[sen.size()] == 1 << 29) cout << -1;
	else cout << dp[sen.size()];

	return 0;
}