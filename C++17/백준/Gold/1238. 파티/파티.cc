#include <bits/stdc++.h>
using namespace std;
int path[1001][1001];
vector<pair<int,int>> node[1001];

void dijk(int x) {
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,x });
	path[x][x] = 0;
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		d *= -1;
		pq.pop();
		for (auto t : node[u]) {
			if (path[x][t.first] > d + t.second) {
				path[x][t.first] = d + t.second;
				pq.push({ -path[x][t.first],t.first });
			}
		}
	}
}

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			path[i][j] = 1 << 28;

	for (int i = 0; i < m; i++) {
		int s, e, d;
		cin >> s >> e >> d; 
		node[s].push_back({e,d});
	}

	for (int i = 1; i <= n; i++)
		dijk(i);
	int mx = 0;

	for (int i = 1; i <= n; i++)
		mx = max(path[i][x] + path[x][i], mx);
	cout << mx;
}