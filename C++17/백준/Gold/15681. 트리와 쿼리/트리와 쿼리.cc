#include <cstdio>
#include <vector>
std::vector<int> vec[100001];
int count[100001];
bool vis[100001];

int check(int root) {
	int cnt = 0;
	for (auto iter = vec[root].begin(); iter != vec[root].end(); iter++) {
		int n = *iter;
		if (vis[n]) continue;
		vis[n] = 1;
		count[n] = check(n);
		cnt += count[n];
	}
	return cnt + 1;
}

int main() {
	int n, r, q;
	scanf("%d %d %d", &n, &r, &q);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	vis[r] = 1;
	count[r] = check(r);
	while (q-- > 0) {
		int u;
		scanf("%d", &u);
		printf("%d\n", count[u]);
	}
	return 0;
}