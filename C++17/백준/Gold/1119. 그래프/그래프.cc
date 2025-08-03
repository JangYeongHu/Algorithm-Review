#include <bits/stdc++.h>
using namespace std;

int parent[50];
bool vis[50];
int cnt;

int find(int x) {
	if (parent[x] != -1) return find(parent[x]);
	return x;
}

void unn(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		cnt++;
		return;
	}
	parent[x] = y;
	vis[y] = 1;
}

int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << "0"; return 0;
	}

	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for(int j = i+1; j < n; j++) {
			if (s[j] == 'Y') {
				unn(i, j); 
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (parent[i] == -1)
			if(vis[i])ans++;
			else { cout << -1; return 0; }
	}

	if (cnt >= ans - 1) cout << ans - 1;
	else cout << -1;

	return 0;
}