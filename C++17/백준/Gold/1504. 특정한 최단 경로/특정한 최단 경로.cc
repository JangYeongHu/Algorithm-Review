#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> node[801];
int path[801][801];
void dijk(int x) {
	priority_queue<pair<int, int>> pq;
	path[x][x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		d *= -1;
		for (auto t : node[u]) {
			if (path[x][t.first] > path[x][u] + t.second) {
				path[x][t.first] = path[x][u] + t.second;
				pq.push({ -path[x][t.first],t.first });
			}
		}
	}
}

int main() {
	int n, e;
	cin >> n >> e;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			path[i][j] = 1 << 28;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}
	int v1, v2;
	cin >> v1 >> v2;
	dijk(1); dijk(v1); dijk(v2);

	int res = min(path[1][v1] + path[v1][v2] + path[v2][n], path[1][v2] + path[v2][v1] + path[v1][n]);

	cout << (res > 1 << 27 ? -1 : res);
}