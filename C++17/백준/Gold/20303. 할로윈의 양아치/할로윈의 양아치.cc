#include <bits/stdc++.h>
using namespace std;

int candy[30001];
int parent[30001];

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

void unn(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (parent[a] > parent[b]) swap(a, b);
	candy[a] += candy[b];
	parent[a] += parent[b]; parent[b] = a;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> candy[i];
		parent[i] = -1;
	}

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		unn(a, b);
	}
	vector<pair<int, int>> bags;
	for (int i = 1; i <= n; i++) {
		if (parent[i] < 0) {
			bags.push_back({ -parent[i],candy[i] });
		}
	}
	vector<vector<int>> dp(bags.size() + 1, vector<int>(k, 0));
	int idx = 1;
	for (auto [w, v] : bags) {
		for (int i = 1; i < k; i++) {
			if (i - w < 0)dp[idx][i] = dp[idx - 1][i];
			else dp[idx][i] = max(dp[idx-1][i], dp[idx-1][i - w] + v);
		}
		idx++;
	}

	cout << dp.back()[k-1];

	return 0;
}