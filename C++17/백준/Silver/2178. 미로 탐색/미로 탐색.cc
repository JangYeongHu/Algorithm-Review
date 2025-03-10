#include <bits/stdc++.h>
using namespace std;
int miro[101][101], dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x < 0 || x >= m || y < 0 || y >n) continue;
			if (miro[y][x] != 1) continue;
			miro[y][x] = miro[t.second][t.first] + 1;
			q.push({ x,y });
		}
	}

	printf("%d", miro[n - 1][m - 1]);
}