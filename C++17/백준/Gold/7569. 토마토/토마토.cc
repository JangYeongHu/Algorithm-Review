#include <bits/stdc++.h>
using namespace std;
int box[101][101][101], dx[] = { 1,-1,0,0,0,0 }, dy[] = { 0,0, 1,-1,0,0 }, dz[] = { 0,0,0,0,1,-1 };
typedef struct { int x, y, z; }pos;
int n, m, h;

int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				cin >> box[i][j][k];
	queue<pos> q;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (box[i][j][k] == 1) {
					q.push({ k,j,i });
				}
	
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int tx = t.x + dx[i];
			int ty = t.y + dy[i];
			int tz = t.z + dz[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n || tz < 0 || tz >= h) continue;
			if (box[tz][ty][tx] != 0) continue;
			box[tz][ty][tx] = box[t.z][t.y][t.x] + 1;
			q.push({ tx,ty,tz });
		}
	}

	int res = 0;

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				res = max(res, box[i][j][k]); 
				if (box[i][j][k] == 0) { cout << -1; return 0; }
			}

	cout << res-1;
}