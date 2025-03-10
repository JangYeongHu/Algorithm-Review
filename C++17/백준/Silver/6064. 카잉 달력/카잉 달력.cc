#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int a = m, b = n;
		while (b) {
			int r = a % b;
			a = b;
			b = r;
		}
		int now = x;
		y %= n;
		while (now % n != y && m*n/a > now) now += m;
		if (now % n == y) cout << now <<"\n";
		else cout << -1 << "\n";
	}
}