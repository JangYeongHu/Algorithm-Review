#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> nodes[1001];
int dis[1001];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ b,c });
	}
	int s, e;
	cin >> s >> e;
	for (int i = 1; i <= n; i++)  dis[i] = 1 << 28;
	dis[s] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		d *= -1;
		if (dis[u] < d) continue;
		for (auto t : nodes[u]) {
			if (dis[t.first] > dis[u] + t.second) {
				dis[t.first] = dis[u] + t.second;
				pq.push({ -dis[t.first],t.first });
			}
		}
	}

	cout << dis[e];
}