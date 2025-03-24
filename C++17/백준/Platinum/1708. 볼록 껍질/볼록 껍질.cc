#include <bits/stdc++.h>
using namespace std;
struct pos { int x, y;

	static int ccw(pos a, pos b, pos c) {
		long long res = 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y);
		if (res > 0) return 1;
		if (res < 0) return -1;
		return 0;
	}

};

int main() {
	cin.tie(0);ios::sync_with_stdio(0);
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
			if (a.y != b.y) return a.y < b.y;
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
		while (st.size() > 1) {
			pos first = st.back();
			st.pop_back();
			pos second = st.back();
			if (pos::ccw(first, cities[i], second) > 0) { st.push_back(first); break; }
		}
		st.push_back(cities[i]);
	}

	cout << st.size();
}