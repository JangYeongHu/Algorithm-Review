#include <bits/stdc++.h>
using namespace std;
string area[100];
bool area_1[100][100];
bool vis[100][100];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n;

void bfs(int x, int y) {
	queue<pair<int,int>> q;

	q.push({ x,y });
	vis[y][x] = 1;
	char tar = area[y][x];
	if (tar == 'R' || tar == 'G') area_1[y][x] = 1;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = t.first + dx[i];
			int ty = t.second + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (vis[ty][tx] || area[ty][tx] != tar ) continue;
			vis[ty][tx] = 1;
			q.push({ tx,ty });
			if (tar == 'R' || tar == 'G') area_1[ty][tx] = 1;
		}
	}
}

void bfs_1(int x, int y) {
	queue<pair<int, int>> q;

	q.push({ x,y });
	vis[y][x] = 0;
	bool tar = area_1[y][x];
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = t.first + dx[i];
			int ty = t.second + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (!vis[ty][tx] || area_1[ty][tx] != tar) continue;
			vis[ty][tx] = 0;
			q.push({ tx,ty });
		}
	}
}

int main() {
	cin >> n;

	for(int i = 0; i < n; i++)
			cin >> area[i];

	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!vis[i][j]) {
				bfs(j,i);
				res++;
			}
	int res_1 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (vis[i][j]) {
				bfs_1(j, i);
				res_1++;
			}
	cout << res << " " << res_1;
}