#include <bits/stdc++.h>
using namespace std;
int parent[100001][20];
int height[100001];
int square[20];
vector<int> nodes[100001];

void dfs(int x) {
	for (int n : nodes[x]) {
		if (height[n]) continue;
		height[n] = height[x] + 1;
		parent[n][0] = x;
		dfs(n);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	square[0] = 1;
	for (int i = 1; i < 20; i++) square[i] = square[i - 1] * 2;
	height[1] = 1;
	dfs(1);

	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];

	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (height[a] < height[b]) swap(a, b);
		while (height[a] != height[b]) {
			int idx = 0;
			while (height[a] - height[b] > square[idx + 1]) idx++;
			a = parent[a][idx];
		}

		while (a != b) {
			int idx = 0;
			while (parent[a][idx + 1] != parent[b][idx + 1]) idx++;
			a = parent[a][idx]; b = parent[b][idx];
		}
		cout << a << "\n";
	}


}