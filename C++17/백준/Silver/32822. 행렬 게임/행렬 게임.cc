#include <bits/stdc++.h>
using namespace std;
int hoon[1000][1000];
int chan[1000][1000];
int store[1000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> hoon[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> chan[i][j];
	}

	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < n; j++) {
			mx = max(abs(hoon[j][i] - chan[j][i]), mx);
		}
		store[i] = mx;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int t; cin >> t; t--;
		ans += store[t];
	}
	cout << ans;
	return 0;
}