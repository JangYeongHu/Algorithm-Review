#include <bits/stdc++.h>
using namespace std;
int parent[100001];
int cnt[100001];

vector<vector<int>> ans;

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

void unn(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (parent[a] > parent[b])swap(a, b);
	cnt[a] += cnt[b];
	parent[a] += parent[b]; parent[b] = a;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> cnt[i];
		parent[i] = -1;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		unn(a, b);
	}

	ans.push_back(vector<int>(k));

	for (int i = 1; i <= n; i++) {
		if (parent[i] >= 0) continue;
		ans.push_back(vector<int>(k));
		int s = ans.size() - 1;
		for (int j = 1; j < k; j++) {
			if (j + parent[i] < 0) ans[s][j] = ans[s - 1][j];
			else {
				ans[s][j] = max(ans[s - 1][j], ans[s - 1][j + parent[i]] + cnt[i]);
			}
		}
	}
	cout << ans[ans.size() - 1][k - 1];

	return 0;
}