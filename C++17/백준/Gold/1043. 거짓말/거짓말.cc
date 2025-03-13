#include <bits/stdc++.h>
using namespace std;
int parent[51];
int party[51];

void unn(int x, int y) {
	while (parent[x] != x) x = parent[x];
	while (parent[y] != y) y = parent[y];

	if (x > y) swap(x, y);
	parent[y] = x;

}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	int know_num;
	cin >> know_num;
	for (int i = 0; i < know_num; i++) {
		int t;
		cin >> t;
		parent[t] = 0;
	}

	for (int i = 0; i < m; i++) {
		int num,p;
		cin >> num >> p;
		party[i] = p;
		for (int j = 1; j < num; j++) {
			int t;
			cin >> t;
			unn(t, p);
		}
	}

	int res = 0;
	for (int i = 0; i <= m; i++) {
		int x = party[i];
		while (parent[x] != x) x = parent[x];
		if (x != 0) { res++; }
	}
	cout << res;
}