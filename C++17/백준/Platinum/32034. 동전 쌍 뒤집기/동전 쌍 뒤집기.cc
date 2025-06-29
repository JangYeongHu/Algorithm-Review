#include <bits/stdc++.h>
using namespace std;

long long ans() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	string s; cin >> s;
	stack<int> st;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') {
			if (!st.empty() && st.top() % 2 != i % 2) {
				res += i - st.top();
				st.pop();
			}
			else {
				st.push(i);
			}
		}
	}
	return st.empty()?res:-1;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cout << ans() << "\n";
	}
	return 0;
}