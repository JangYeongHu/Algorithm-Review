#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	double ax, ay, bx, by, px, py, r;
	cin >> ax >> ay >> bx >> by >> px >> py >> r;
	double ans1 = dist(ax,ay,bx,by);
	double ans2 = max(0.0,dist(ax, ay, px, py)-r) + max(0.0,dist(bx,by,px,py)-r);
	cout << fixed << setprecision(10);
	cout << min(ans1, ans2);
}