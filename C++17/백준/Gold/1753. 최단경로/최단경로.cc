#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> nodes[20001];
int path[20001];

void dijk(int x) {
	priority_queue<pair<int,int>> pq;
	pq.push({0,x});
	path[x] = 0;
	while (!pq.empty()) {
		auto [d,u] = pq.top();
		d *= -1;
		pq.pop();
		for (auto t : nodes[u]) {
			if (path[t.first] > t.second + d) {
				path[t.first] = t.second + d;
				pq.push({ -path[t.first],t.first });
			}
		}
	}
}

int main() {
	int V, e,k;
	cin >> V >> e >> k;
	for (int i = 1; i <=  V; i++) path[i] = 1 << 28;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		nodes[u].push_back({ v,w });
	}

	dijk(k);
	for (int i = 1; i <= V; i++) {
		if (path[i] == 1 << 28) cout << "INF\n";
		else cout << path[i] << "\n";
	}
}