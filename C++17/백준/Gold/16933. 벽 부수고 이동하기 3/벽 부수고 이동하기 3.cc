#include <cstdio>
#include <queue>
using namespace std;
typedef struct { int x,y,m,k,d; } element;
bool vis[11][1000][1000];
bool map[1000][1000];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	vis[k][0][0] = 1;
	queue<element> q;
	q.push({ 0,0,1,k,0 });
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		if (t.x == m - 1 && t.y == n - 1) {
			printf("%d", t.m);
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			if (x < 0 || x >= m || y < 0 || y >= n) continue;
			if (vis[t.k][y][x]) continue;
			if (map[y][x]) {
				if (!t.k) continue;
				if (t.d) {
					q.push({ t.x,t.y,t.m + 1,t.k,!t.d });
					continue;
				}
				q.push({ x,y,t.m + 1,t.k - 1,!t.d });
				vis[t.k][y][x] = 1;
				continue;
			}
			vis[t.k][y][x] = 1;
			q.push({ x,y,t.m + 1,t.k,!t.d });
		}
	}
	printf("-1");
	return 0;
}