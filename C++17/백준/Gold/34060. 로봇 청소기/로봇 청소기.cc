
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

namespace std {
	template <>
	struct hash<pair<int, int>> {
		size_t operator()(const pair<int, int>& p) const {
			return 1LL * p.first * 1000003 + p.second;
		}
	};
}

unordered_set<pii> pos;
unordered_set<pii> vis;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void bfs(pii p) {
	queue<pii> q;
	q.push(p);
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = t.first + dx[i];
			int ny = t.second + dy[i];
			if (!pos.count({ nx,ny }) || vis.count({ nx,ny })) continue;
			vis.insert({ nx, ny });
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0); 
	int n,x = 0,idx = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (t <= x) idx++;
		pos.insert({ idx,t });
		x = t;
	}
	int ans = 0;
	for (auto p : pos) {
		if (vis.count(p)) continue;
		ans++;
		bfs(p);
	}

	cout << ans << "\n" << n;

	return 0;
}