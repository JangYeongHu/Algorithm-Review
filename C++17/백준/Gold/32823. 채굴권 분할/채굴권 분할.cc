#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
using Point = pair<double, double>;

double PI = acos(-1);

int ccw(Point p1, Point p2, Point p3) {
	double res = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0;
}

Point to_pos(double t) {
	double x = sin(t / 10 * PI / 180)*1000;
	double y = cos(t / 10 * PI / 180)*1000;
	return { x,y };
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
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pair<Point, Point>> lines;
	for (int i = 0; i < n; i++) {
		double r1, r2;
		cin >> r1 >> r2;
		Point p1 = to_pos(r1),p2 = to_pos(r2);
		lines.push_back({ p1,p2 });
	}

	double p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;


	Point r1 = to_pos(p1), r2 = to_pos(p3);

	r1.x = r1.x * p2 / 1000;
	r1.y = r1.y * p2 / 1000;
	r2.x = r2.x * p4 / 1000;
	r2.y = r2.y * p4 / 1000;

	int ans = 0;
	for (auto [a, b] : lines)
		ans += cross(a, b, r1, r2);

	if (ans % 2) cout << "NO";
	else cout << "YES";
}