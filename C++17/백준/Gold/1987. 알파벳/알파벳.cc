#include <bits/stdc++.h>
using namespace std;
int r, c;
char mp[20][20];
bool vis[26];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };

int dfs(int x, int y) {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || tx >= c || ty < 0 || ty >= r) continue; 
		if (vis[mp[ty][tx] - 'A']) continue;
		vis[mp[ty][tx] - 'A'] = 1;
		res = max(res,dfs(tx, ty));
		vis[mp[ty][tx] - 'A'] = 0;
	}
	return res + 1;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> mp[i][j];
	vis[mp[0][0] - 'A'] = 1;
	cout << dfs(0, 0);
}