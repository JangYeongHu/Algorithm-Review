#include <bits/stdc++.h>
using namespace std;

int ans() {
	int n, k,w;
	int time[1001], cnt[1001] = { 0, }, dp[1001] = { 0, };
	vector<int> order[1001];
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> time[i];
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		order[x].push_back(y);
		cnt[y]++;
	}
	cin >> w;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 0) { q.push(i); dp[i] = time[i]; }
	while (!q.empty()) {
		int t = q.front();
		if (t == w) return dp[w];
		q.pop();
		for (int node : order[t]) {
			cnt[node]--;
			dp[node] = max(dp[node], dp[t] + time[node]);
			if (cnt[node] == 0) {
				q.push(node);
			}
		}
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cout << ans() << "\n";
	}
}