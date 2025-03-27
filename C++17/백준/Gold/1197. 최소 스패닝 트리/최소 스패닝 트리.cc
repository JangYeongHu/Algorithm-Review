#include <bits/stdc++.h>
using namespace std;
struct edge { int a, b,w; };
vector<edge> edges;
int parent[10001];
int height[10001];

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= v;i++) parent[i] = i;
	for (int i = 0; i < e; i++) {
		edge e;
		cin >> e.a >> e.b >> e.w;
		edges.push_back(e);
	}
	sort(edges.begin(), edges.end(),
		[](edge a, edge b) {
			return a.w < b.w;
		});
	int cnt = 0, res = 0;
	for (edge e : edges) {
		if (cnt == v - 1) break;
		int a = e.a, b = e.b;
		while (parent[a] != a) a = parent[a];
		while (parent[b] != b) b = parent[b];
		if (a == b) continue;
		if (height[a] > height[b]) swap(a, b);
		parent[a] = b;
		if (height[a] == height[b]) height[b]++;
		cnt++;
		res += e.w;
	}
	cout << res;
}