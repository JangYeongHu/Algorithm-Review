#include <bits/stdc++.h>
using namespace std;
#define SZ 1'000'001
int card[200000];
int sz[SZ];
int parent[SZ];
int height[SZ];

int find(int x) {
	while (parent[x] >= 0) x = parent[x];
	return x;
}

void unn(int a,int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;

	if (height[a] > height[b]) {
		parent[a] += parent[b]; parent[b] = a;
	}
	else {
		parent[b] += parent[a]; parent[a] = b;
	}
	if (height[a] == height[b]) {
		height[b]++;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;

	for (int i = 0; i < SZ; i++) parent[i] = -1;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		unn(card[i], t);
	}

	for (int i = 0; i < n; i++) sz[find(card[i])]++;

	unordered_set<int> us;
	int ans = 0;
	for (int i = 0; i < SZ; i++) {
		int x = find(i);
		if (us.find(x) != us.end()) continue;
		us.insert(x);
		ans += min(-parent[x],sz[x]);
	}

	cout << ans;

	return 0;
}