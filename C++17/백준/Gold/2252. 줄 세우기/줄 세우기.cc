#include <bits/stdc++.h>
using namespace std;
int main() {
	int cnt[32001];
	vector<int> son[32001];
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		son[a].push_back(b);
		cnt[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 0) q.push(i);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		cout << t << " ";
		for (int s : son[t]) {
			cnt[s]--;
			if (cnt[s] == 0)q.push(s);
		}
	}
}