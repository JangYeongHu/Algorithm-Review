#include <bits/stdc++.h>
using namespace std;

int get(int y, int x) {
	int n = max(abs(x), abs(y));
	int nx = n, ny = n;
	int ans = (n*2+1)*(n*2+1);
	if (ny == y) {
		while (nx != x && nx > -n) { nx--; ans--; }
		return ans;
	}
	nx = -n; ans -= 2 * n;
	if (nx == x) {
		while (ny != y && ny > -n) { ny--; ans--; }
		return ans;
	}
	ny = -n; ans -= 2 * n;
	if (ny == y) {
		while (nx != x && nx < n) { nx++; ans--; }
		return ans;
	}
	nx = n; ans -= 2 * n;
	while (ny != y) { ny++; ans--; }
	return ans;
}
vector<vector<int>> ans;
int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	int mx = 0;
	for (int i = a; i <= c; i++) {
		ans.push_back(vector<int>(0));
		for (int j = b; j <= d; j++) {
			int t = get(i, j);
			mx = max(t, mx);
			ans.back().push_back(t);
		}
	}
	int fo = 0;
	while (mx) { mx /= 10; fo++; }
	for (auto a : ans) {
		for (int b : a) {
			cout << setw(fo) << b << " ";
		}
		cout << "\n";
	}
	return 0;
}