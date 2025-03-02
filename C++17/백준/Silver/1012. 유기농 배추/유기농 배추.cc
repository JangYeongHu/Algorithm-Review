#include <iostream>
#include <queue>
using namespace std;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };

void bfs(int n,int m,int y, int x, int arr[][50]) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	arr[y][x] = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = t.first + dx[i];
			int ty = t.second + dy[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
			if (!arr[ty][tx]) continue;
			arr[ty][tx] = 0;
			q.push({ tx,ty });
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t-- > 0) {
		int arr[50][50] = { 0, };
		int m, n, k;
		cin >> m >> n >> k;
		while (k-- > 0) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		int res = 0;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] == 1) {
					res++;
					bfs(n,m,i, j, arr);
				}
		cout << res << "\n";
	}
	return 0;
}