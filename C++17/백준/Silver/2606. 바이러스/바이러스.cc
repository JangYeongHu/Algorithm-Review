#include <iostream>
#include <vector>

using namespace std;

vector<int> computer[101];
bool vis[101];

int dfs(int x) {
	vis[x] = 1;
	int res = 1;
	for (int a : computer[x]) {
		if (vis[a]) continue;
		res+=dfs(a);
	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
	cout << dfs(1)-1;

	return 0;
}