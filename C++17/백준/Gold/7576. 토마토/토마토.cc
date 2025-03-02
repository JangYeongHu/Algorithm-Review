#include <iostream>
#include <queue>
using namespace std;
int dp[1000][1000], dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int main() {
	int n, m;
	queue<pair<int, int>> q;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> dp[i][j];
			if (dp[i][j] == 1) q.push({ j,i });
		}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
			if (dp[ty][tx] != 0) continue;
			dp[ty][tx] = dp[y][x] + 1;
			q.push({ tx, ty });
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (dp[i][j] == 0) { cout << -1; return 0; }
			res = max(res, dp[i][j]);
		}
	cout << res - 1;
	return 0;
}