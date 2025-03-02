#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> node[1001];

void dfs(int v, bool vis[1001]) {
	cout << v << " ";
	vis[v] = 1;
	for (int a : node[v]) {
		if (vis[a]) continue;
		dfs(a, vis);
	}
}

void bfs(int v, bool vis[1001]) {
	cout << v << " ";
	vis[v] = 1;
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int a : node[t]) {
			if (vis[a]) continue;
			vis[a] = 1;
			cout << a << " ";
			q.push(a);
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for (int i = 0; i < 1001; i++)
		sort(node[i].begin(),node[i].end());
	bool dvis[1001] = { 0, }, bvis[1001] = { 0, };
	dfs(v, dvis);
	cout << "\n";
	bfs(v, bvis);

	return 0;
}