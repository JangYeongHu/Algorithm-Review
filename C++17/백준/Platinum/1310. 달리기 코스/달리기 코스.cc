#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using Point = pair<ll, ll>;

Point operator + (Point p1, Point p2) { return { p1.x + p2.x,p1.y + p2.y }; }
Point operator - (Point p1, Point p2) { return { p1.x - p2.x,p1.y - p2.y }; }
ll operator * (Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
ll operator / (Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }
int Sign(ll v) { return (v > 0) - (v < 0); }
ll Dist(Point p1, Point p2) { return (p2 - p1) * (p2 - p1); }
ll SignedArea(Point p1, Point p2, Point p3) { return (p2 - p1) / (p3 - p1); }
int CCW(Point p1, Point p2, Point p3) { return Sign(SignedArea(p1, p2, p3)); }


vector<Point> ConvexHull(vector<Point> points) {
	if (points.size() <= 1) return points;
	swap(points[0], *min_element(points.begin(), points.end()));
	sort(points.begin() + 1, points.end(), [&](auto a, auto b) {
		int dir = CCW(points[0], a, b);
		if (dir != 0) return dir > 0;
		return Dist(points[0], a) < Dist(points[0], b);
		});

	vector<Point> hull;
	for (auto p : points) {
		while (hull.size() >= 2 && CCW(hull[hull.size() - 2], hull.back(), p) <= 0)
			hull.pop_back();
		hull.push_back(p);
	}
	return hull;
}

pair<Point, Point> Calipers(vector<Point> hull) {
	int n = hull.size(); ll mx = 0; Point a, b;
	for (int i = 0, j = 0; i < n; i++) {
		while (j + 1 < n && (hull[i + 1] - hull[i]) / (hull[j + 1] - hull[j]) >= 0) {
			ll now = Dist(hull[i], hull[j]);
			if (now > mx) mx = now, a = hull[i], b = hull[j];
			j++;
		}
		ll now = Dist(hull[i], hull[j]);
		if (now > mx) mx = now, a = hull[i], b = hull[j];
	}
	return { a,b };
}



int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<Point> points;
	for (int i = 0; i < n; i++) {
		Point p;
		cin >> p.x >> p.y;
		points.push_back(p);
	}
	vector<Point> hull = ConvexHull(points);

	auto pp = Calipers(hull);
	cout << Dist(pp.first, pp.second);
}