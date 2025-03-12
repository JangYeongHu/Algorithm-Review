#include <bits/stdc++.h>
using namespace std;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int main() {
	char campus[601][601];
	int n, m;
	cin >> n >> m;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') q.push({ j,i });
		}
	int res = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = t.first + dx[i];
			int ty = t.second + dy[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
			if (campus[ty][tx] == 'X') continue;
			if (campus[ty][tx] == 'P') res++;
			campus[ty][tx] = 'X';
			q.push({ tx,ty });
		}
	}
	if (res) cout << res;
	else cout << "TT";

}