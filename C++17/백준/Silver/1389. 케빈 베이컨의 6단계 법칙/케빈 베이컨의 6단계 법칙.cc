#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(0), ios::sync_with_stdio(0),cout.tie(0)

bool fre[101][101];
int n, m;

int bfs(int x) {
	vector<int> vis(n+1, -1);
	queue<int> q;
	vis[x] = 0;
	q.push(x);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!fre[t][i]) continue;
			if (vis[i] != -1) continue;
			vis[i] = vis[t] + 1;
			q.push(i);
		}
	}

	int res = 0;
	for (int a : vis) res += a;
	return res;
}

int main() {
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		fre[a][b] = fre[b][a] = 1;
	}
	int res = 1 << 28,ra = 0;
	for (int i = 1; i <= n; i++) {
		int t = bfs(i);
		if (t < res) {
			res = t;
			ra = i;
		}
	}
	cout << ra;
	return 0;
}