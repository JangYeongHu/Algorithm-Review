#include <bits/stdc++.h>
using namespace std;

int a[10000];
int b[10000];
int c[10000];
int area[10000][2];
int n, w;
void solve(int idx) {
	for (int i = idx; i < n; i++) {
		b[i] = a[i - 1] + 1;
		if (area[i - 1][0] + area[i][0] <= w) b[i] = min(b[i], c[i - 1] + 1);

		c[i] = a[i - 1] + 1;
		if (area[i - 1][1] + area[i][1] <= w) c[i] = min(c[i], b[i - 1] + 1);

		a[i] = min(b[i] + 1, c[i] + 1);
		if (area[i][0] + area[i][1] <= w) {
			a[i] = min(a[i - 1] + 1, a[i]);
		}
		if (i == 1) {
			if (area[i - 1][0] + area[i][0] <= w && area[i - 1][1] + area[i][1] <= w)
				a[i] = 2;
		}
		else if (i > 1) {
			if (area[i - 1][0] + area[i][0] <= w && area[i - 1][1] + area[i][1] <= w)
				a[i] = min(a[i], a[i - 2] + 2);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;

	while (t--) {
		cin >> n >> w;
		for (int i = 0; i < n; i++) cin >> area[i][0];
		for (int i = 0; i < n; i++) cin >> area[i][1];

		if (n == 1) {
			cout << ((area[0][0] + area[0][1]) <= w ? 1 : 2) << "\n";
			continue;
		}

		a[0] = (area[0][0] + area[0][1] <= w) ? 1 : 2;
		b[0] = c[0] = 1;
		solve(1);
		int ans = a[n - 1];



		if (area[0][0] + area[n - 1][0] <= w) {

			b[1] = 2;
			c[1] = (area[0][1] + area[1][1]) <= w ? 1 : 2;
			a[1] = ((area[1][0] + area[1][1]) <= w) || c[1] == 1 ? 2 : 3;
			solve(2);
			ans = min(ans, c[n - 1] + 1);
		}

		if (area[0][1] + area[n - 1][1] <= w) {
			b[1] = (area[0][0] + area[1][0]) <= w ? 1 : 2;
			c[1] = 2;
			a[1] = ((area[1][0] + area[1][1]) <= w) || (b[1] == 1) ? 2 : 3;
			solve(2);
			ans = min(ans, b[n - 1] + 1);
		}

		if (area[0][0] + area[n - 1][0] <= w && area[0][1] + area[n - 1][1] <= w) {
			a[1] = (area[1][0] + area[1][1]) <= w ? 1 : 2;
			b[1] = 1;
			c[1] = 1;
			solve(2);
			ans = min(ans, a[n - 2] + 2);
		}
		cout << ans << "\n";
	}
	return 0;
}