#include <bits/stdc++.h>
using namespace std;
int main() {
	int ans = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		int res = 0;
		if (a == b && b == c && c == a) {
			res = 10000 + a * 1000;
		}
		else if (a == b) {
			res = 1000 + a * 100;
		}
		else if (c == b) {
			res = 1000 + b * 100;
		}
		else if (a == c) {
			res = 1000 + a * 100;
		}
		else {
			res = max(max(a,b),c)*100;
		}
		ans = max(ans, res);
	}
	cout << ans;
}