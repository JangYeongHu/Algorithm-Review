#include <iostream>
using namespace std;
struct point { 
	int x, y;
	static int ccw(point a, point b, point c) {
		long long result = 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y);
		if (result > 0) return 1;
		if (result < 0) return -1;
		return 0;
	}
};

bool check_bigger(point p1, point p2) {
	if (p1.x == p2.x) return p1.y > p2.y;
	return p1.x > p2.x;
}

int check_cross(point p1, point p2, point p3, point p4) {

	int c1 = point::ccw(p3, p1, p2) * point::ccw(p4, p1, p2);
	int c2 = point::ccw(p1, p3, p4) * point::ccw(p2, p3, p4);

	if (c1 > 0 || c2 > 0) return 0;
	if (c1 != 0 || c2 != 0) return 1;
	if (check_bigger(p1, p2)) swap(p1, p2);
	if (check_bigger(p3, p4)) swap(p3, p4);
	if (check_bigger(p2, p3)) return 1;
	return 0;
}

int main() {
	point p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;
	cout << check_cross(p1, p2, p3, p4);


	return 0;
}