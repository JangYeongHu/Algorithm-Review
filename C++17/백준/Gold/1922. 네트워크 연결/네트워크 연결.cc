#include <iostream>
#include <queue>
using namespace std;
int parent[1001];
int height[1001];

int find(int x) {
	while (parent[x] != x)x = parent[x];
	return x;
}

int merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return 0;
	if (height[x] > height[y]) parent[y] = x;
	else parent[x] = y;
	if (height[x] == height[y]) height[y]++;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	priority_queue<vector<int>> pq;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ -c,a,b });
	}
	int cnt = 0,res = 0;
	while (cnt < n-1) {
		vector<int> t = pq.top();
		pq.pop();
		if (merge(t[1], t[2])) {
			cnt++; res += -t[0];
		}
	}
	cout << res;
	return 0;
}