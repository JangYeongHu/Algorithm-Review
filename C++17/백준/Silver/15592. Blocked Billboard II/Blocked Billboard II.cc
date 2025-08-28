#include <bits/stdc++.h>
using namespace std;
int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;
	int ans = (x2 - x1) * (y2 - y1);

	int wid = x2-x1;
	int hei = y2-y1;
	if (y3 <= y1 && y4 >= y2) {
		if (x4 >= x2) ans -= (x2 - max(x1, x3)) * hei;
		else if (x3 <= x1 && x4 > x1) ans -= (x4 - x1) * hei;
	}
	else if (x3 <= x1 && x4 >= x2) {
		if (y4 >= y2) ans -= (y2 - max(y1, y3)) * wid;
		else if (y3 <= y1 && y4 > y1) ans -= (y4 - y1) * wid;
	}

	cout << ans;

	return 0;
}