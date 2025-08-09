#include <bits/stdc++.h>
using namespace std;
int n;
double mn;

void bf(int cnt,int now,int x,vector<pair<int,int>> & v) {
	if (cnt == n/2) {
		double xs = 0, ys = 0;
		for (int i = 0; i < n; i++) {
			if (x & (1 << i)) {
				xs += v[i].first;
				ys += v[i].second;
			}
			else {
				xs -= v[i].first;
				ys -= v[i].second;
			}
		}
		double now = sqrt(xs * xs + ys * ys);
		mn = min(mn, now);
		return;
	}
	for (int i = now; i < n; i++) {
		if (x & (1 << i)) continue;
		bf(cnt+1,i+1,x | (1 << i), v);
	}
}

void get() {
	mn = 1e18;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	bf(1,0,1, v);
	cout << fixed << setprecision(8) << mn << "\n";
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		get();
	}
	return 0;
}