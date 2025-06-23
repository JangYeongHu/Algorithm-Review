#include <bits/stdc++.h>


using namespace std;
vector<int> e[1'000'001];
bool vis[1'000'001];
int dp[1'000'001][2];

void get(int node) {
	vis[node] = 1;
	dp[node][1] += 1;
	for (int t : e[node]) {
		if (vis[t]) continue;
		get(t);
		dp[node][0] += dp[t][1];
		dp[node][1] += min(dp[t][0], dp[t][1]);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	get(1);
	cout << min(dp[1][0],dp[1][1]);

	return 0;
}