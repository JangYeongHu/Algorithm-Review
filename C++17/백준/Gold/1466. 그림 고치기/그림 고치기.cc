#include <bits/stdc++.h>
using namespace std;
int n, m;
char pic[50][50];
bool vis[50][50];
int pr[50 * 50];
int height[50 * 50];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int make_one(int x, int y) {
	return x * 50 + y;
}

int find(int x) {
	while (pr[x] != x) x = pr[x];
	return x;
}

void unn(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (height[a] > height[b])
		pr[b] = a;
	else {
		pr[a] = b;
	}
	if (height[a] == height[b]) {
		height[b]++;
	}
}

void bfs(int x, int y) {
	vis[y][x] = 1;
	queue<int> q;
	q.push(make_one(x, y));
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = t / 50 + dx[i];
			int ny = t % 50 + dy[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (vis[ny][nx] || pic[ny][nx] == '.') continue;
			vis[ny][nx] = 1;
			unn(t, make_one(nx, ny));
			q.push(make_one(nx, ny));
		}
	}
}

bool check() {
	bool is_change = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (pic[y][x] == '.') continue;
			int temp = y;
			for (int k = n - 1; k >= y; k--)
				if (pic[k][x] == '#' && find(make_one(x, k)) == find(make_one(x, y)))
				{
					temp = k; break;
				}
			for (int k = y; k < temp; k++) {
				if (pic[k][x] == '.') {
					is_change = 1;
					pic[k][x] = '#';
				}
			}

			temp = x;
			for (int k = m - 1; k >= x; k--)
				if (pic[y][k] == '#' && find(make_one(k, y)) == find(make_one(x, y)))
				{
					temp = k; break;
				}
			for (int k = x; k < temp; k++) {
				if (pic[y][k] == '.') {
					is_change = 1;
					pic[y][k] = '#';
				}
			}
		}
	}
	return is_change;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m * 50 + n; i++) pr[i] = i;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			pic[i][j] = s[j];
		}
	}

	bool is_change = 1;

	while (is_change) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				vis[i][j] = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] || pic[i][j] == '.') continue;
				bfs(j, i);
			}
		}

		is_change = check();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << pic[i][j];
		}
		cout << "\n";
	}

	return 0;
}