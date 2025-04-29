#include <bits/stdc++.h>
using namespace std;
vector < pair<int, int> >nodes[500];
vector<int> path[500];
int dis[500];
bool deleted[500][500];

int dijkstra(int s,int d) {
	dis[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		d *= -1;
		if (d > dis[u]) continue;
		for (auto t : nodes[u]) {
			if (deleted[u][t.first]) continue;
			if (dis[t.first] > dis[u] + t.second) {
				path[t.first].clear();
				path[t.first].push_back(u);
				dis[t.first] = dis[u] + t.second;
				pq.push({ -dis[t.first],t.first });
			}
			else if (dis[t.first] == dis[u] + t.second) {
				path[t.first].push_back(u);
			}
		}
	}
	return dis[d];
}

void bfs(int d) {
	queue<int> q;
	q.push(d);
	int vis[500] = { 0, };
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (vis[t]) continue;
		vis[t] = 1;
		for (int n : path[t]) {
			q.push(n);
			deleted[n][t] = 1;
		}
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n + m == 0) break;
		for (int i = 0; i < n; i++) {
			dis[i] = 1 << 28;
			for (int j = 0; j < n; j++) deleted[i][j] = 0;
			nodes[i].clear();
			path[i].clear();
		}
		int s, d;
		cin >> s >> d;
		for (int i = 0; i < m; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			nodes[u].push_back({ v,p });
		}
		dijkstra(s, d);
		bfs(d);
		for (int i = 0; i < n; i++) { dis[i] = 1 << 28; path[i].clear(); }
		int res = dijkstra(s, d);
		if (res == 1 << 28) cout << "-1\n";
		else cout << res << "\n";
	}
	return 0; 
}