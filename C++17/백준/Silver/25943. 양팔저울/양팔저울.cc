#include <bits/stdc++.h>
using namespace std;
int w[] = { 100,50,20,10,5,2,1 };
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int left, right;
	cin >> left >> right;
	for (int i = 0; i < n - 2; i++) {
		int t; cin >> t;
		if (left <= right) left += t;
		else right += t;
	}

	int cha = abs(left - right);
	int ans = 0;
	for (int i : w) {
		if (cha == 0) break;
		ans += cha / i;
		cha %= i;
	}
	cout << ans;
	return 0;
}