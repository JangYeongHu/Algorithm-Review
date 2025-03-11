#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(0), ios::sync_with_studio(0); cout.tie(0);
int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		string dp[10001];
		int a, b;
		cin >> a >> b;
		queue<int> q;
		q.push(a);
		dp[a] = "";
		while (!q.empty()) {
			int t = q.front(),x;
			q.pop();
			if (t == b) { cout << dp[b] << "\n"; break; }
			x = t * 2 % 10000;
			if (dp[x].empty() && x != a) { dp[x] = dp[t] + "D", q.push(x); }
			x = t ? t - 1 : 9999;
			if (dp[x].empty() && x != a) { dp[x] = dp[t] + "S", q.push(x); }
			x = t * 10 % 10000 + t / 1000;
			if (dp[x].empty() && x != a) { dp[x] = dp[t] + "L", q.push(x); }
			x = t / 10 + t % 10 * 1000;
			if (dp[x].empty() && x != a) { dp[x] = dp[t] + "R", q.push(x); }
		}
	}
}