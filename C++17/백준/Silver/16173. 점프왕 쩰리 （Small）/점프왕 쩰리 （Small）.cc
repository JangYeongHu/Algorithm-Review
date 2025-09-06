#include <bits/stdc++.h>
using namespace std;
int dx[] = { -1,1,0,0, }, dy[] = { 0,0,1,-1 };
int arr[3][3];
int vis[3][3];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	queue<pair<int,int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i] * arr[y][x];
			int ty = y + dy[i] * arr[y][x];
			if (tx == n - 1 && ty == n - 1) {
				cout << "HaruHaru";
				return 0;
			}
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (vis[ty][tx]) continue;
			vis[ty][tx] = 1;
			q.push({ tx,ty });
		}
	}

	cout << "Hing";

	return 0;
}