#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define MAX 1'000'000'001
using ll = long long;
using Point = pair<ll, ll>;
vector<Point> res;
int ccw(Point p1, Point p2, Point p3) {
	ll res = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0; 
}

bool check(Point p) {
	int cnt = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res[i].x == p.x && res[i].y == p.y) return 1;
		int ab = ccw(p, { MAX,p.y+1 }, res[i]) * ccw(p, { MAX,p.y+1 }, res[(i + 1) % res.size()]);
		int cd = ccw(res[i], res[(i + 1) % res.size()], p) * ccw(res[i], res[(i + 1) % res.size()], { MAX,p.y+1 });
		if (ab < 0 && cd < 0) cnt++;
	}
	if (cnt % 2) return 1;
	return 0;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		Point p;
		cin >> p.x >> p.y;
		res.push_back(p);
	}

	for (int i = 0; i < 3; i++) {
		Point p;
		cin >> p.x >> p.y;
		cout << check(p) << "\n";
	}

}