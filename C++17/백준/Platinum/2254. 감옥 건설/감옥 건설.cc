#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
using ll = long long;
using Point = pair<ll, ll>;
vector<Point> pillars;
int ccw(Point p1, Point p2, Point p3) {
	ll res = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0; 
}

bool check(Point p, vector<int>& res) {
	for (int i = 0; i < res.size(); i++) {
		if (ccw(p, { 100001,p.y }, pillars[res[i]]) * ccw(p, { 100002,p.y }, pillars[res[(i + 1) % (res.size() + 1)]]) < 0) return 0;
	}
	return 1;
}

void convex_hull(vector<int> & st) {
	sort(pillars.begin(), pillars.end(),
		[](Point p1, Point p2) {
			if (p1.y != p2.y) return p1.y < p2.y;
			return p1.x < p2.x;
		});

	Point p0 = pillars[0];

	sort(pillars.begin(), pillars.end(),
		[p0](Point p1, Point p2) {
			int res = ccw(p0, p1, p2);
			if (res != 0) return res > 0;
			if (p1.y != p2.y) return p1.y < p2.y;
			return p1.x < p2.x;
		});

	for (int i = 0; i < pillars.size(); i++) {
		while (st.size() > 2) {
			int first = st.back();
			st.pop_back();
			int second = st.back();
			if (ccw(pillars[i], pillars[first], pillars[second]) <= 0) { st.push_back(first); break; }
		}
		st.push_back(i);
	}
}

bool cross(Point s1, Point e1, Point s2, Point e2) {
	int ab = ccw(s1, e1, e2) * ccw(s1, e1, s2);
	int cd = ccw(s2, e2, s1) * ccw(s2, e2, e1);
	if (ab == 0 && cd == 0) {
		if (s1 > e1) swap(s1, e1);
		if (s2 > e2) swap(s2, e2);
		return !(e1 < s2 || e2 < s1);
	}
	return ab <= 0 && cd <= 0;
}


int main() {
	Point p;
	int n; cin >> n >> p.x >> p.y;
	for (int i = 0; i < n; i++) {
		Point p;
		cin >> p.x >> p.y;
		pillars.push_back(p);
	}
	int ans = 0;

	while (pillars.size() > 2) {
		vector<int> res;
		convex_hull(res);
		if(check(p, res)) break;
		for(int i = res.size()-1; i >= 0; i--)
			pillars.erase(pillars.begin() + res[i]);
		ans++;
	}
	cout << ans;
}