#include <iostream>
#include <queue>
using namespace std;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 }, map[1001][1001];
bool vis[1001][1001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	pair<int, int> start;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) { start = { j,i }; map[i][j] = 0; vis[i][j] = 1; }
		}
	queue < pair<int, int>> q;
	q.push(start);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
			if (map[ty][tx] != 1 || vis[ty][tx]) continue;
			map[ty][tx] = map[y][x] + 1;
			vis[ty][tx] = 1;
			q.push({ tx,ty });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (map[i][j] == 1 && vis[i][j] == 0) cout << "-1 ";
			else cout << map[i][j] << " ";
		cout << "\n";
	}

	return 0;
}