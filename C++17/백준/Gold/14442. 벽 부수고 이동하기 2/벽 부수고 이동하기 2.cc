#include <cstdio>
#include <queue>

using namespace std;
bool map[1000][1000];
int dp[1000][1000][11];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	queue<vector<int>> q;
	q.push({ 0,0,k });
	dp[0][0][k] = 1;
	while (!q.empty()) {
		vector<int> t = q.front();
		q.pop();
		if (t[0] == m - 1 && t[1] == n - 1) {
			printf("%d",dp[t[1]][t[0]][t[2]]);
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int tx = t[0] + dx[i];
			int ty = t[1] + dy[i];
			if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
			if (!map[ty][tx]) {
				if (dp[ty][tx][t[2]]) continue;
				dp[ty][tx][t[2]] = dp[t[1]][t[0]][t[2]] + 1;
				q.push({ tx,ty,t[2] });
			}
			else if (t[2] > 0) {
				if (dp[ty][tx][t[2] - 1]) continue;
				dp[ty][tx][t[2] - 1] = dp[t[1]][t[0]][t[2]] + 1;
				q.push({ tx,ty,t[2] - 1 });
			}
		}
	}
	printf("-1");
	return 0;
}