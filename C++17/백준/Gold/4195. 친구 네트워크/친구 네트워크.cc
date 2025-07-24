#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& p) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x], p);
}

void unn(int a, int b, vector<int>& p) {
	a = find(a,p);
	b = find(b, p);
	if (a != b) {
		if (p[b] < p[a]) swap(a, b);
		p[a] += p[b]; p[b] = a;
	}
	cout << -p[a] << "\n";
}

void get() {
	int n; cin >> n;
	vector<int> parent(2*n,-1);
	unordered_map<string, int> mp;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		if (mp.find(a) == mp.end()) {
			mp.insert({ a, idx++ });
		}

		if (mp.find(b) == mp.end()) {
			mp.insert({ b, idx++ });
		}
		int ai = mp[a],bi = mp[b];
		unn(ai, bi, parent);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		get();
	}
	return 0;
}