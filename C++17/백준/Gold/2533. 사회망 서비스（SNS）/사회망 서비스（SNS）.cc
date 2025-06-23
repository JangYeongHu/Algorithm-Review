#include <bits/stdc++.h>


using namespace std;
vector<int> edges[1'000'001];
vector<int> tree[1'000'001];
int dp[1'000'001];
bool vis[1'000'001];

void dfs(int node) {
	vis[node] = 1;
	for (int t : edges[node]) {
		if (vis[t]) continue;
		tree[node].push_back(t);
		dfs(t);
	}
}

int get(int node) {
	int re1 = 1,re2 = 0;
	if (dp[node]) return dp[node];
	vector<int> sons;
	
	for (int t : tree[node]) {
		sons.push_back(t);
		re1 += get(t);
	}
	re2 += sons.size();
	for (int t : sons) {
		for(int k: tree[t])
			re2 += get(k);
	}

	dp[node] = min(re1, re2);

	return dp[node];

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1);

	cout << get(1);

	return 0;
}