#include <bits/stdc++.h>
using namespace std;
vector<int> apart;
int jido[25][25], dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int n;

void bfs(int x, int y) {
	queue < pair<int, int>> q;
	int cnt = 1;
	q.push({ x,y });
	jido[y][x] = 0;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = t.first + dx[i];
			int ty = t.second + dy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= n) continue;
			if (jido[ty][tx] != 1) continue;
			jido[ty][tx] = 0;
			q.push({ tx,ty });
			cnt++;
		}
	}
	apart.push_back(cnt);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &jido[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (jido[i][j])bfs(j, i);

	sort(apart.begin(), apart.end());
	cout << apart.size() << "\n";
	for (int a : apart) cout << a << "\n";
}