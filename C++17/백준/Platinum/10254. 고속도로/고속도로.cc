#include <bits/stdc++.h>
using namespace std;
struct pos { int x, y; 

	pos operator-(pos a) {
	return { x - a.x,y - a.y };
	}

	static int ccw(pos a, pos b, pos c) { // a가 끼인 점, 
		long long res = 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y);
		if (res > 0) return 1;
		if (res < 0) return -1;
		return 0;
	}

};

long long dist(pos a, pos b) {
	return 1LL * pow((b.x - a.x), 2) + 1LL * pow((b.y - a.y), 2);
}

void solve() {
	int n;
	cin >> n;
	vector<pos> cities(n);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cities[i] = { x,y };
	}
	sort(cities.begin(), cities.end(),
		[](pos a, pos b) {
			if (a.x == b.x) return a.y < b.y;
			return a.x < b.x;
		});

	pos p1 = cities[0];

	sort(cities.begin() + 1, cities.end(),
		[p1](pos a, pos b) {
			int ccw = pos::ccw(p1, b, a);
			if (ccw != 0) return ccw < 0;
			if (a.y != b.y) return a.y < b.y;
			return a.x < b.x;
		});


	vector<pos> st;
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == 1) st.push_back(cities[i]);
		while (st.size() > 1) {
			pos first = st.back();
			st.pop_back();
			pos second = st.back();
			if (pos::ccw(first, cities[i], second) > 0) { st.push_back(first); break; }
		}
		st.push_back(cities[i]);
	}

	int a = 0, b = 1, sz = st.size();
	pair<pos, pos> ans = { st[a],st[b] };
	while (1) {
		if (dist(ans.first, ans.second) < dist(st[a], st[b])) ans = { st[a],st[b] };
		if (pos::ccw(st[(a + 1) % sz], st[(b + 1) % n] - (st[b] - st[(a + 1) % sz]), st[a]) < 0) {
			a = (a + 1) % sz;
			if (a == 0) break;
		} else {
				b = (b + 1) % sz;
				if (b == 1) break;
		}
	}
	cout << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}