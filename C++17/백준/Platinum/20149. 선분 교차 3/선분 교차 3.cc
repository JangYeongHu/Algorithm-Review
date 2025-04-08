#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
using ll = long long;
using Point = pair<ll, ll>;
int ccw(Point p1, Point p2, Point p3) {
	ll res = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0; 
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

int cross(Point s1, Point e1, Point s2, Point e2, pair<double,double> & res) {
	if (!cross(s1, e1, s2, e2)) return 0;
	if ((e1.y - s1.y) * (e2.x - s2.x) == (e2.y - s2.y) * (e1.x - s1.x)) {
		if (s1 > e1) swap(s1, e1);
		if (s2 > e2) swap(s2, e2);
		if (e1 == s2) { res = s2; return 1; }
		if (e2 == s1) { res = s1; return 1; }
		return -1;
	}

	res.x = (s1.x * e1.y - s1.y * e1.x) * (s2.x - e2.x) - (s1.x - e1.x) * (s2.x * e2.y - s2.y * e2.x);
	res.y = (s1.x * e1.y - s1.y * e1.x) * (s2.y - e2.y) - (s1.y - e1.y) * (s2.x * e2.y - s2.y * e2.x);
	double p = (s1.x - e1.x) * (s2.y - e2.y) - (s1.y - e1.y) * (s2.x - e2.x);
	res.x /= p;
	res.y /= p;
	return 1;
}


int main() {
	Point s1, e1, s2, e2;
	cin >> s1.x >> s1.y >> e1.x >> e1.y;
	cin >> s2.x >> s2.y >> e2.x >> e2.y;
	pair<double, double> res;
	int a = cross(s1, e1, s2, e2,res);
	if (a == 0) cout << 0;
	else {
		cout << "1\n";
		if (a != -1) printf("%.9lf %.9lf", res.x, res.y);
	}
}