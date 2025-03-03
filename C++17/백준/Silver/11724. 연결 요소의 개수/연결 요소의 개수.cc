#include <iostream>
#include <vector>
using namespace std;
bool vis[1001] = { 1, };
vector<int> node[1001];

void dfs(int x) {
	vis[x] = 1;
	for (int s : node[x]) {
		if (vis[s]) continue;
		dfs(s);
	}
}

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i);
		res++;
	}
	cout << res;
	return 0;
}