#include <bits/stdc++.h>
using namespace std;
struct road { int a, b, c; };
road roads[1'000'000] ;
int height[100'001];
int parent[100'001];

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> roads[i].a >> roads[i].b >> roads[i].c;
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sort(roads, roads + m,
		[](road a, road b) {
		return a.c < b.c;
	});
	int cnt = 0,ans = 0;
	for (road r : roads) {
		if (cnt == n - 2) break;
		int a = r.a, b = r.b;
		while (parent[a] != a) a = parent[a];
		while (parent[b] != b) b = parent[b];

		if (a == b) continue;
		ans += r.c; cnt++;
		if (height[a] == height[b]) height[a]++;
		if (height[a] > height[b]) parent[b] = a;
		else parent[a] = b;
	}
	cout << ans;
}