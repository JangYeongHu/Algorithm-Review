#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> nodes[10001];
bool vis[10001];
pair<int, int> dfs(int x) {
	vis[x] = 1;
	int mx = 0,ind = -1;
	for (auto a : nodes[x]) {
		if (vis[a.first])continue;
		auto b = dfs(a.first);
		if (b.second+a.second > mx) { mx = b.second+a.second; ind = b.first; }
	}
	vis[x] = 0;
	if (ind == -1) return { x,0 };
	return { ind, mx };	
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		nodes[a].push_back({ b,w });
		nodes[b].push_back({ a,w });
	}

	int node = dfs(1).first;
	cout << dfs(node).second;
}