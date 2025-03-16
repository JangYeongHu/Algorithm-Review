#include <bits/stdc++.h>
using namespace std;
typedef struct { int s, e, t; } edge;

string fun() {
	int n, m, w;
	vector<edge> edges;
	int dis[501];
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++) dis[i] = 1 << 28;
	dis[1] = 0;
	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		edges.push_back({ s,e,t });
		edges.push_back({ e,s,t });
	}
	for (int i = 0; i < w; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		edges.push_back({ s,e,-t });
	}

	for (int i = 0; i < n; i++) {
		for (edge e : edges) {
			if (dis[e.s] + e.t < dis[e.e]) {
				if (i == n-1) return "YES";
				dis[e.e] = dis[e.s] + e.t;
			}
		}
	}
	return "NO";
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc-- > 0) {
		cout << fun() << "\n";
	}
}