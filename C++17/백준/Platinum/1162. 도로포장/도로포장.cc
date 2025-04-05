#include <bits/stdc++.h>
using namespace std;
struct node {
	long long dis; int nxt, k;
	bool operator<(const node& other) const {
		return dis > other.dis;
	}
};
vector<pair<int, int>> nodes[10000];
long long dis[10001][21];

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ b,c });
		nodes[b].push_back({ a,c });
	}

	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= k; j++)
			dis[i][j] = 1LL << 60;

	priority_queue<node> pq;
	pq.push({0,1,0});
	while (!pq.empty()) {
		auto [d,u,k_] = pq.top();
		pq.pop();
		if (dis[u][k_] != d) continue;
		for (auto t : nodes[u]) {
			if (k_ <= k && dis[t.first][k_] > dis[u][k_] + t.second) {
				dis[t.first][k_] = dis[u][k_] + t.second;
				pq.push({ dis[t.first][k_],t.first,k_ });
			}
			if (k_+1 <= k && dis[t.first][k_+1] > dis[u][k_]) {
				dis[t.first][k_+1] = dis[u][k_];	
				pq.push({ dis[t.first][k_+1],t.first,k_+1 });
			}
		}
	}
	long long ans = 1LL*1<<60;
	for (int i = 0; i <= k; i++) ans = min(ans, dis[n][i]);
	cout << ans;
}