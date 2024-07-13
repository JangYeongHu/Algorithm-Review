#include <iostream>
#include <algorithm>

using namespace std;

char map[1001][1001];
int parent[1000 * 1000];
bool vis[1000 * 1000];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };


int find(int x, int y) {
	int r = y * 1000 + x;
	while (parent[r] != r) r = parent[r];
	return r;
}

void t_union(int x, int y, int tx, int ty) {
	int a = find(x, y);
	int b = find(tx, ty);
	if (a == b) return;
	parent[b] = a;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 1000 * 1000; i++) parent[i] = i;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 4; k++) {
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx > m || tx < 0 || ty > n || ty < 0) continue;
				if (k == 0 && map[ty][tx] == 'R' || k == 1 && map[ty][tx] == 'L' || k == 2 && map[ty][tx] == 'U' || k == 3 && map[ty][tx] == 'D') t_union(j, i, tx, ty);
			}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int k = find(j, i);
			if (vis[k]) continue;
			res++;
			vis[k] = 1;
		}
	cout << res;
	return 0;
}