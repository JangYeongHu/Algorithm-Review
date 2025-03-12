#include <bits/stdc++.h>
using namespace std;
int vis[101];
int ladder[101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a] = b;
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (1) {
		int t = q.front();
		if (t == 100) break;
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int tp = t + i;
			if (tp > 100) continue;
			if (vis[tp] != 0) continue;
			vis[tp] = vis[t] + 1;
			if (ladder[tp] != 0) {
				if (vis[ladder[tp]] != 0) continue;
				vis[ladder[tp]] = vis[tp];
				q.push(ladder[tp]);
			}
			else {
				q.push(tp);
			}
		}
	}
	cout << vis[100]-1;
}