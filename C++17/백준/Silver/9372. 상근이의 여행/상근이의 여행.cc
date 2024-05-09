#include <cstdio>
#include <queue>

int main() {
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		int n, m,a,b;
		bool vis[1001] = { 0 };
		std::vector<int> v[1001];
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) v[i].resize(0);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		std::queue<int> q;
		q.push(1);
		vis[1] = 1;
		int cnt = 0;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto iter = v[t].begin(); iter != v[t].end(); iter++) {
				if (vis[*iter]) continue;
				vis[*iter] = 1;
				q.push(*iter);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}