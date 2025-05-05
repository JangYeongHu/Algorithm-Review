#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> nodes[40001];
int parent[17][40001];
int price[17][40001];
bool vis[40001];
int height[40001];

void dfs(int n) {
	vis[n] = 1;
	for (auto t : nodes[n]) {
		if (vis[t.first]) continue;
		height[t.first] = height[n] + 1;
		parent[0][t.first] = n;
		price[0][t.first] = t.second;
		dfs(t.first);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		nodes[a].push_back({ b,c });
		nodes[b].push_back({ a,c });
	}
	dfs(1);

	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			price[i][j] = price[i - 1][j] + price[i - 1][parent[i - 1][j]];
		}
	}

	int m; cin >> m;
	while (m-- > 0) {
		int a, b; cin >> a >> b;
		int ans = 0;
		if (height[b] > height[a]) swap(a, b);

		for (int i = 16; i >= 0; i--) {
			if (height[a] - height[b] >= (1 << i)) {
				ans += price[i][a];
				a = parent[i][a];
			}
		}
		if (a != b) {
			for (int i = 16; i >= 0; i--) {
				if (parent[i][a] != 0 && parent[i][a] != parent[i][b]) {
					ans += price[i][a] + price[i][b];
					a = parent[i][a];
					b = parent[i][b];
				}
			}
			ans += price[0][a] + price[0][b];
		}
		cout << ans << "\n";
	}
	return 0;
}