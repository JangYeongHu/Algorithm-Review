#include <bits/stdc++.h>
using namespace std;
struct pos { int x, y; };
bool operator<=(pos a, pos b) {
	if (a.x == b.x) return a.y <= b.y;
	return a.x <= b.x;
}
struct line { pos p1, p2; };

int ccw(pos a, pos b, pos c) {
	long long res = 1LL * (a.x - c.x) * (b.y - c.y) - 1LL * (a.y - c.y) * (b.x - c.x);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0;
}

bool mn(pos x, pos y) {
	if (x.x == y.x) return x.y > y.y;
	return x.x > y.x;
}

bool is_crossed(line l1, line l2) {

	int c1 = ccw(l2.p1, l1.p1, l1.p2) * ccw(l2.p2, l1.p1, l1.p2);
	int c2 = ccw(l1.p1, l2.p1, l2.p2) * ccw(l1.p2, l2.p1, l2.p2);
	if (c1 == 0 && c2 == 0) return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
	if (c1 > 0 || c2 > 0) return 0;
	return 1;
}

int main() {
	line l1, l2;
	cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y;
	cin >> l2.p1.x >> l2.p1.y >> l2.p2.x >> l2.p2.y;
	if (mn(l1.p1, l1.p2)) swap(l1.p1, l1.p2);
	if (mn(l2.p1, l2.p2)) swap(l2.p1, l2.p2);
	cout << is_crossed(l1, l2);
}