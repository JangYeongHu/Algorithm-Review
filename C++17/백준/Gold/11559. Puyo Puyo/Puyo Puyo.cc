#include <bits/stdc++.h>
using namespace std;
char field[12][6];
bool vis[12][6];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
vector<pair<int, int>> chain;

bool bfs(int x, int y,bool k) {
	vis[y][x] = 1;
	int cnt = 1;
	char c = field[y][x];
	if (k) field[y][x] = '.';
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		auto [tx, ty] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ix = tx + dx[i];
			int iy = ty + dy[i];
			if (ix < 0 || ix >= 6 || iy < 0 || iy >= 12) continue;
			if (vis[iy][ix] || field[iy][ix] != c) continue;
			vis[iy][ix] = 1;
			if (k) field[iy][ix] = '.';
			q.push({ ix,iy });
			cnt++;
		}
	}

	if (cnt > 3) return 1;
	return 0;
}

void check() {
	chain.clear();
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			vis[i][j] = 0;

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++) {
			if (vis[i][j] || field[i][j] == '.') continue;
			if (bfs(j, i,0))
				chain.push_back({ j,i });
		}
}

void chaining() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			vis[i][j] = 0;

	for (auto [x, y] : chain)
		bfs(x, y, 1);

	for (int i = 0; i < 6; i++) {
		for (int j = 11; j >= 0; j--) {
			if (field[j][i] == '.') {
				for (int k = j - 1; k >= 0; k--) {
					if (field[k][i] != '.') { swap(field[k][i], field[j][i]); break; }
				}
			}
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++) 
			cin >> field[i][j];

	int ans = 0;
	while(1) {
		check();
		if (chain.empty()) break;
		chaining();
		ans++;
	}
	cout << ans;
}